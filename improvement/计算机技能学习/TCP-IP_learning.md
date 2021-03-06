# TCP-IP详解卷1:协议 读书笔记

## 概述

- 引言
  - TCP/IP协议族：允许运行不同操作系统的不同计算机互相通信【internet协议族】
- 分层
  - 网络协议通常分层开发，每一层负责不同的通信功能，TCP/IP协议族是四个层次多个协议的组合
  - 链路层
  - 网络层
  - 运输层
  - 应用层
   ---
  - 互联网：网络的网络
    - 构造互联网：通过路由器、网桥连接两个以上的网络
      - 路由器：用于网络互联的硬件盒
      - 网桥：不同于路由器在网络层上连接，网桥在链路层进行互联
- TCP/IP的分层
- 互联网的地址
  - 互联网的每个接口必须有唯一的internet地址（也称作IP地址）
    - 地址32位通常写成四个十进制数，每个整数对应一个字节
    - 有三类IP地址：单播地址、广播地址、多播地址
- 域名系统
  - 提供IP地址和主机名之间映射信息的分布的数据库
- 封装
  - 应用程序将数据送入协议栈中，然后逐个通过每一层直到被当作一串比特流送入网络
- 分用
  - 当目的主机收到一个以太网数据帧时， 数据就开始从协议栈中由底向上升，同时去掉各层协议所加

## 互联网协议入门 阮一峰的网络日志

- 概述
  - 五层模型
    - 互联网分成若干层。
  - 层与协议
    - 互联网的每一层，都定义了很多协议。总称"互联网协议"（Internet Protocol Suite）
    - 以太网协议（Ethernet）
    - IP协议
      1. DHCP协议
      2. DNS协议
      3. ARP协议
      4. 路由协议
    - UDP协议、TCP协议
    - HTTP协议

 ---

- 实体层：
  - 它是把电脑连接起来的物理手段。
  - 它规定了网络的电气特性
  - 在电脑间（或电脑与服务器间）传送0和1的电信号。

 ---

- 链接层：【以太网数据包】
  - 它确定了0和1的分组方式（规定了0和1的解读方式）
  - 以太网协议（Ethernet）【是一种主流的电信号分组方式】
    - 数据包
      - 一组电信号构成一个数据包"帧"（Frame）
      - 由标头（Head）和数据（Data）组成
  --*MAC地址**（Media Access Control）
    - 网卡地址，即数据包的发送和接收地址。 
  - 广播
    - 标头中包含收方的MAC地址，每个计算机都会读取到这个包，将标头中的MAC地址与自身进行比较
  --*有了数据包的定义、网卡的MAC地址、广播的发送方式，链接层就可以在多台计算机之间传送数据了**

 ---

- 网络层：【IP数据包】建立主机到主机的联系
  - 依靠广播方式，理论上可以单单依靠MAC地址进行通信，但广播的范围局限在子网络中，于是新增路由方式向不同的子网络发送数据
  - 网络层引进一套新的地址，使得我们能够区分不同的计算机是否属于同一个子网络
  --*IP协议**：规定网络地址的协议，定义IP地址。互联网上每一台计算机都会分配到一个IP地址。
    - 分配IP地址：IP地址 = 网络部分 + 主机部分
    - 同一个子网络中的计算机，IP地址网络部分相同
      - 子网掩码：用于分离网络主机部分
    - IP数据包：直接放入以太网数据包的数据部分
    - 数据包的发送方式
      - （通常情况下，IP地址已知，MAC地址未知）（可以判断是否属于同一个子网络）
      - 跨子网络：传送到网关（gateway）
        - 路由协议：向不同的子网络分发数据包
      - 同子网络：运用ARP协议，由IP地址得到MAC地址
  - DHCP协议：动态、静态IP地址
  - 四个参数
    - 本机的IP地址
    - 子网掩码
    - 网关的IP地址
      - 可通过ARP协议得到网关的MAC地址
    - DNS的IP地址
      - DNS协议：将目标网址转换成IP地址

 ---

- 传输层：建立端口到端口的通讯
  - 端口（port）：使用同一网卡的不同程序的编号，让程序取到发给自己的数据，实现端到端的通信
  - UDP协议
    - 在数据前面加上端口号
    - UDP数据包：放入IP数据包的数据部分
  - *TCP协议**（加上确认机制）

 ---

- 应用层：规定应用层的数据格式。
  - HTTP协议：镶嵌在TCP协议中
