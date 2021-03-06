# Linux 学习
## 目录
* 什么是Linux
* Linux的来源以及特性
* 如何学习Linux
---
## 什么是Linux
 * 计算机基本组成
 * 操作系统：由核心kernel、硬件的接口工具kernelTools、对外应用程序application组成

     应具有的功能
     * 系统呼叫接口
     * 进程管理
     * 内存管理
     * 文件系统管理
     * 装置驱动 
 * Linux是一个包含内核及其接口工具的操作系统，或者说是操作系统最底层的核心
 * 它提供了一个完整的操作系统中最底层的硬件控制和资源管理的完整架构
---
## Linux的来源以及特性
 * 文件概念诞生unix原型
 * 用C语言重写，Unix正式版本发行，具有可移植性
 * GNU计划，为了建立一个自由开放的Unix操作系统，开源精神
 > 开放源码仍保留软件权利，自由软件才是完全开放的
 * GPL公共通用许可证，对应于自由软件
 > 编译器，编辑器存在区别
 * 依照现有的unix规范POSIX对Linux进行优化，让核心能够适合所有软件的开发
 * 成立核心网站和虚拟团队，强调务实
   
   特色
 * 自由开放
 * 硬件门槛低
 * 功能强大稳定，能独立作业
   
   优缺点
 * 稳定的系统
 * 免费
 * 安全
 * 资源消耗相对较低
 * 适合微电脑操作系统
 * 服务不算完善
 * 图形界面不够好
   
   补充
 * 软件移植：同一款游戏，根据操作系统提供的工具不同，程序的内容自然也就不同。修改程序代码使其适应其他操作系统的环境，这个动作即为移植
---
## 如何学习Linux
 * Linux的应用
     * 网络服务器：提供internet一种以上网络服务的主机
     * 工作站计算机：作为数值分析、学习用途的工具
     * 桌面计算机
 * 从头学习
     * 硬件知识
     * Linux基础知识
     * 文字编辑器vi
     * shell命令、shell script
     * TCP/IP 协议
## 命令行模式下
 * 命令行模式概念
 > shell :将使用者输入的命令翻译给内核kernel
 > bash
 * 下达指令
     * 指令的结构
         * 四部分（可选）
         * 之间用空格分割，即单个部分不能用命令隔开
         * shell从第一个字符开始读取，故第一个字符必须是可执行命令，且此前可以有任意字符
     * 常用指令
     