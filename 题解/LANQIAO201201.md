---
title: 蓝桥杯 2012年第三届省赛 C/C++ B组 01 微生物增殖
date: 2021-03-24 08:19:36
tags:
- 模拟
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post4.jpg
---

## 题目描述

假设有两种微生物 X 和 Y
X 出生后每隔 3 分钟分裂一次（数目加倍），Y 出生后每隔 2 分钟分裂一次（数目加倍）。
一个新出生的 X，半分钟之后吃掉 1 个 Y，并且，从此开始，每隔 1 分钟吃 1 个 Y。
现在已知有新出生的 X = 10，Y = 89，求 60 分钟后 Y 的数目。
如果 X = 10，Y = 90 呢？
本题的要求就是写出这两种初始条件下，60 分钟后 Y 的数目。
题目的结果令你震惊吗？这不是简单的数字游戏！真实的生物圈有着同样脆弱的性质！也许因为你消灭的那只 Y 就是最终导致 Y 种群灭绝的最后一根稻草！

## 题目分析

将时间乘以2，即以0.5分钟为单位时间。我们发现：
t % 2 == 1&emsp;Y = Y - X
t % 4 == 0&emsp;Y = 2 \* Y
t % 6 == 0&emsp;X = 2 \* X

```c++
#include<iostream>
using namespace std;

int main()
{
	int x,y,t=120;
	cin>>x>>y;
	int n=1,f=0;
	while(n <= t) {
		if(f==0 && n%2==1) {
			y-=x;
			if(y <= 0) {
				f=1;
			}
		}
		if(f==0 && n%4==0) {
			y*=2;
		}
		if(n%6 == 0) {
			x*=2;
		}
		n++;
	}
	cout<<"x="<<x<<endl;
	if(f == 0) {
		cout<<"y="<<y<<endl;
	} else {
		cout<<"y=0"<<endl;
	}
	
	return 0;
 }
```

## 题目答案

**0**
**94371840**