# 时间复杂度

## 问题描述

分析算法的时间复杂度是评价算法性能的重要方式之一，对于同一问题来说，拥有线性时间复杂度的算法往往比拥有平方级别时间复杂度的算法要快很多，因此拥有线性时间复杂度的算法往往优于拥有平方级别时间复杂度的算法。

通常，可以根据输入n的值确定算法的运行时间，n可以表示要排序的对象数，多边形顶点数等等。现给出一段简易的程序，程序规则如下，其中<number>可以是任何非负整数：

```
< Program > ::= "BEGIN" < Statementlist > "END" 

< Statementlist > ::= < Statement > | < Statement > < Statementlist > 

< Statement > ::= < LOOP-Statement > | < OP-Statement > 

< LOOP-Statement > ::= < LOOP-Header > < Statementlist > "END" 

< LOOP-Header > ::= "LOOP" < number > | "LOOP n" 

< OP-Statement > ::= "OP" < number >
```

针对该规则下的程序的运行时间可以如下计算：执行OP语句所花费的时间与其参数指定的时间相同（即为number）。LOOP语句到其对应的END之间所有语句执行的次数与LOOP后的参数相同（即为number或n）。程序运行时间是其组成部分的时间总和。因此，总运行时间通常取决于n。

## 输入格式

输入一段程序，空格和换行符可以出现在程序中的任何位置，但不能出现在关键字BEGIN，END，LOOP和OP中或整数值中。LOOP的循环嵌套深度最多为10。

## 输出格式

以n为单位输出程序的运行时间，即输出一个化简后的Y（Y<=10）次多项式，形如“Runtime = a*n^10+b*n^9+ . . . +i*n^2+ j*n+k”，若n的某一项系数为0则直接省略该项,若系数为1则省略其系数。
如果运行时间为0，则只需打印 “Runtime = 0”。

## 样例输入

```
BEGIN
   LOOP n
     LOOP n
       OP 3
       OP 4
       LOOP 4
         OP 3
       END
     END
   END
   OP 7
END
```

## 样例输出

```language
Runtime = 19*n^2+7
```

## 样例说明

Runtime = nx(nx(3+4+4x3))+7=19*n^2+7

## 数据范围说明

LOOP循环嵌套深度<=10且关键字总数不超过50
且所有运算均在int范围内进行
对于测试点1，保证只包含OP语句
对于测试点2,3，保证只有一段Statementlist且只有一层循环
对于测试点4，保证只有一段Statementlist