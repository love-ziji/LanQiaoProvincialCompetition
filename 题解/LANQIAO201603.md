---
title: 蓝桥杯 2016年第七届省赛 C/C++ B组 03 凑算式
date: 2021-03-27 19:34:06
tags:
- 全排列
- 浮点数
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post5.jpg
---

## 题目描述

![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/201603.jpg)
这个算式中 A - I 代表 1 - 9 的数字，不同的字母代表不同的数字。
比如：
6 + 8 / 3 + 952 / 714 就是一种解法，
5 + 3 / 1 + 972 / 486 是另一种解法。
这个算式一共有多少种解法？

## 题目分析

全排列问题，使用 next_permutation() 函数，注意浮点数比较相等。

```c++
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	int sum=0;
	do {
		int x=a[3]*100+a[4]*10+a[5]; //DEF
		int y=a[6]*100+a[7]*10+a[8]; //GHI
		if(fabs(a[0]+(a[1]*y+a[2]*x)*1.0/(a[2]*y) - 10) < 1e-5) {
			sum++;
		}
	} while(next_permutation(a,a+9));
	cout<<sum<<endl;
	
	return 0;
}
```

## 题目答案

**29**

