---
title: 蓝桥杯 2015年第六届省赛 C/C++ B组 03 三羊献瑞
date: 2021-03-23 08:41:15
tags:
- 全排列
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post4.jpg
---

## 题目描述

观察下面的加法算式：
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/201503.jpg)
其中，相同的汉字代表相同的数字，不同的汉字代表不同的数字。
请你填写“三羊献瑞”所代表的 4 位数字（答案唯一），不要填写任何多余内容。

## 题目分析

分析可得汉字 ‘三’ 代表数字 ‘1’；汉字 ‘祥’ 代表的数字不小于 8；汉字 ‘辉’ 和汉字 ‘瑞’ 不可能代表数字 ‘0’，然后使用全排列函数next_permutation()即可。

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[9]={0,2,3,4,5,6,7,8,9}; //a[0]-a[6]分别代表羊、献、瑞、祥、生、辉、气 
	do {
		if(a[3]>=8 && a[2]!=0 && a[5]!=0) {
			int x=1*1000+a[0]*100+a[1]*10+a[2];
			int y=a[3]*1000+a[2]*100+a[4]*10+a[5];
			int z=1*10000+a[0]*1000+a[4]*100+a[2]*10+a[6];
			if(x+y == z) {
				cout<<1<<a[0]<<a[1]<<a[2]<<endl;
				return 0;
			}
		}
	} while(next_permutation(a,a+9));
	
	return 0;
}
```

## 题目答案

**1085**

