---
title: 蓝桥杯 2019年第十届省赛 C/C++ B组 I 后缀表达式
date: 2021-04-12 17:11:40
tags:
- 找规律
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post1.jpg
---

## 题目描述

给定 N 个加号、M 个减号以及 N + M + 1 个整数 A1, A2, · · · , AN+M+1 ，小明想知道在所有由这 N 个加号、M 个减号以及 N + M + 1 个整数凑出的合法的后缀表达式中，结果最大的是哪一个？
请你输出这个最大的结果。
例如使用1 2 3 + -，则 “2 3 + 1 -” 这个后缀表达式结果是 4，是最大的。
【输入格式】
第一行包含两个整数 N 和 M。
第二行包含 N + M + 1 个整数 A1, A2, · · · , AN+M+1。
【输出格式】
输出一个整数，代表答案。
【样例输入】
1 1
1 2 3
【样例输出】
4
【评测用例规模与约定】
对于所有评测用例，0 ≤ N, M ≤ 100000，−10^9 ≤ Ai ≤ 10^9。

## 题目分析

分为以下几种情况：
1、如果全是加号，那么直接将所有的数字相加。
2、如果有减号：
如果有一个减号，我们可以转化为 ...+...-(...+...+...) 的形式，因此有一个减号的情况可以视为有一个或多个减号的情况。
如果有多个减号，我们可以转化为 ...+...-...-(...+...-...) 的形式，将减号放到括号里面即可变成加号，因此有多个减号的情况可以视为有一个或多个减号的情况。
即有减号即可视为有一个或多个减号。
如果全是正数，视为只有一个减号，把最小的那个数减去。
如果有正有负，所有正数匹配正号，所有负数匹配负号，即：将它们的绝对值相加。
如果全是负数，除最大的负数之外全部匹配负号。

```c++
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,m,minNum=1e9,maxNum=-1e9,a[200001];
	long long sum=0;
	cin>>n>>m;
	for(int i=0;i<n+m+1;i++) {
		cin>>a[i];
		sum+=a[i];
		minNum=min(minNum,a[i]);
		maxNum=max(maxNum,a[i]);
	}
	if(m != 0) {
		if(minNum > 0) { //全是正数 
			sum-=2*minNum;
		} else {
			sum=0;
			for(int i=0;i<n+m+1;i++) { //有正有负 
				sum+=abs(a[i]);
			}
			if(maxNum < 0) { //全是负数 
				sum+=maxNum*2;
			}
		}
	}
	cout<<sum<<endl;
	
	return 0;
}
```