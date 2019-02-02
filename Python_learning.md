# Python编程 从入门到实践 读书笔记

## 0 小方法

### 0.1 实践

## 1 起步

### 1.1 搭建编程环境

 * 编译器：将高级语言翻译成低级语言的程序
 * （文本）编辑器：用来对程序进行修改的程序
     * 语法突出功能
 * 解释器：把高级语言一行一行转译运行
     * Python自带了一个在终端运行的解释器
        ```
        Steven-MacBook:~ steven$ python3
        Python 3.6.6rc1 (v3.6.6rc1:1015e38be4, Jun 12 2018, 01:14:33)
        [GCC 4.2.1 Compatible Apple LLVM 6.0 (clang-600.0.57)] on darwin
        Type "help", "copyright", "credits" or "license" for more information.
        >>> print('hello world')
        hello world
        >>> ^D //或者使用exit()
        Steven-MacBook:~ steven$
        ```

### 1.4 从终端运行Python程序

 > 可参考 terminal.md 命令行使用

 * cd 命令
 * python 命令
 ```
 Steven-MacBook:Python steven$ python3 hello.py
 hello world!
 ```

## 2 变量和简单的数据类型

### 2.1 py文件的运行状况

 * .py指出这是一个Python程序，因此编辑器（sublime text）将使用Python解释器（CPython）来运行它
 * python解释器读取整个程序，确定其中每个单词的含义

### 2.2 变量

 * 在程序中可随时修改变量的值，没有类型限制
 * 注意变量的命名
 * 注意变量名导致的错误

### 2.3 字符串

 * 使用引号括起来的都是字符串
 * 字符串操作函数（.upper/.lower/.title/+)
 * 空白：在编程中泛指任何非打印字符
     * .strip() 返回原变量拷贝并去除空白（.lstrip/.rstrip)

### 2.4 数字

 * 整数

 > 不同于C语言，整数除法返回的是浮点数

     ```
     >>> 3 / 2 
     1.5
     >>> 3 ** 2 
     9
     ```
 * 浮点数
     * 计算结果可能是不准确的，原因是计算机内部数字的表示方式
 * 输出：适当使用str函数，保证数字按照期望的方式输出

### 2.5 编写注释

 * 目的：阐述代码的目的以及实现方式

## 3 列表

 * 概念：由一系列按特定顺序排列的元素组成

     * 表示语法：`bicycles = ['trek', 'cannondale', 'redline', 'specialized']`

     * 访问：`bicycles[0]`

     > ***索引从0开始***

     * 可以指定索引为负数 `bicycles[-1]` 返回最后一个列表元素

 * 修改

     * 指定索引更改列表元素

     * 在列表末尾添加元素 .append()

     * 插入元素 .insert(0, '...') 此后所有元素右移

     * `del motorcycles[1]` 删除指定位置的元素

     * `motorcycles.remove('ducati')` 删除特定值元素（只删除第一个元素）

     * .pop() 弹出元素，即返回该元素，并将其从原列表中删除

 * 组织列表

     * .sort() 将原列表按照字母顺序排列 `cars.sort(reverse=True)`逆序排列

     * sorted(...) 返回有序列表，不进行改变 

     * .reverse() 反转列表元素

     * len(...) 获取长度，从1开始计算

## 4 操作列表

 * 


