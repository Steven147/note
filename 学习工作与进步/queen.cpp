

/* 
四个四乘四数组 置0


【初始化：选取第一列第一个】
将第一个数组的第一个置1，将第一列，第一行，斜行其余部分置-1，accessible = true，执行n=2

【选取第n列第一个符合条件的，推算下一列，找不到退回上一列下一个，直到最后一列输出】
accessible == true
    取第n-1个数组复制到第n个数组
    如果找到第n个数组第n列第一个0（i行）
        置为1，将第n列，第i行，斜行其余部分置-1
        如果n = 4，
            输出，将accessible置为false，
        否则
            执行第n+1列程序
    否则
        将accessible置为false
        执行第n-1列程序
accessible == false 
    将第n个数组第n列第一个1置为-1，
    accessible置为true
    执行第n列程序

 */