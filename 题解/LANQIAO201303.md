---
title: 蓝桥杯 2013年第四届省赛 C/C++ B组 03 第39级台阶
date: 2021-03-12 21:04:39
tags:
- 递归
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post3.jpg
---

## 题目描述

小明刚刚看完电影《第39级台阶》，离开电影院的时候，他数了数礼堂前的台阶数，恰好是 39 级!
站在台阶前，他突然又想着一个问题：
如果我每一步只能迈上 1 个或 2 个台阶。先迈左脚，然后左右交替，最后一步是迈右脚，也就是说一共要走偶数步。
那么，上完 39 级台阶，有多少种不同的上法呢？
请你利用计算机的优势，帮助小明寻找答案。
要求提交的是一个整数。

## 题目分析

使用递归，以迈上 1 个台阶或迈上 2 个台阶进行递归，递归的终止条件是上完 39 级台阶，若一共走了偶数步则为一种上法。

```c++
#include<iostream>
using namespace std;

int fun(int num,int step) {
	if(num > 39) {
		return 0;
	}
	if(num==39 && step%2==0) {
		return 1;
	}
	
	return fun(num+1,step+1)+fun(num+2,step+1);
}

int main()
{
	cout<<fun(0,0)<<endl;
	
	return 0;
}
```

## 题目答案

**51167078**