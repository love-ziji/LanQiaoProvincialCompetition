---
title: 蓝桥杯 2012年第三届省赛 C/C++ B组 09 夺冠概率
date: 2021-03-10 12:07:03
tags:
- 组合问题
- 随机数
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post5.jpg
mathjax: true
---

## 题目描述

足球比赛具有一定程度的偶然性，弱队也有战胜强队的可能。
假设有甲、乙、丙、丁四个球队。根据他们过去比赛的成绩，得出每个队与另一个队对阵时取胜的概率表：

|        |  甲  |  乙  |  丙  |  丁  |
| :----: | :--: | :--: | :--: | :--: |
| **甲** |  -   | 0.1  | 0.3  | 0.5  |
| **乙** | 0.9  |  -   | 0.7  | 0.4  |
| **丙** | 0.7  | 0.3  |  -   | 0.2  |
| **丁** | 0.5  | 0.6  | 0.8  |  -   |

数据含义：甲对乙的取胜概率为0.1，丙对乙的胜率为0.3，...
现在要举行一次锦标赛。双方抽签，分两个组比，获胜的两个队再争夺冠军。
请你进行 10 万次模拟，计算出甲队夺冠的概率。

## 题目分析

四个队两两比赛，只有 3 种情况（$\frac{C_4^2}{2}$），这 3 种情况分别是甲对乙、甲对丙、甲对丁，分别计算甲获得最终胜利的概率。
要求进行 10 万次模拟，使用 rand() 函数产生 10 万个从 0 到 2 的随机数，0、1、2分别对应上述三种情况甲胜的概率。

```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	double a[3];
	a[0]=0.1*0.2*0.3+0.1*0.8*0.5; //甲对乙
	a[1]=0.3*0.4*0.1+0.3*0.6*0.5; //甲对丙
	a[2]=0.5*0.7*0.1+0.5*0.3*0.3; //甲对丁
	double sum=0;
	srand(time(0)); //以时间为种子
	for(int i=0;i<100000;i++) {
		int n=rand()%3; //产生随机数
		sum+=a[n];
	}
	cout<<sum/100000;
	
	return 0;
}
```
