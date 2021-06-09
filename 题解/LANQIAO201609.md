---
title: 蓝桥杯 2016年第七届省赛 C/C++ B组 09 交换瓶子
date: 2021-03-27 20:49:28
tags:
- 贪心
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post4.jpg
---

## 题目描述

有 N 个瓶子，编号1 ~ N，放在架子上。
比如有 5 个瓶子：
2 1 3 5 4
要求每次拿起 2 个瓶子，交换它们的位置。
经过若干次后，使得瓶子的序号为：
1 2 3 4 5
对于这么简单的情况，显然，至少需要交换 2 次就可以复位。
如果瓶子更多呢？你可以通过编程来解决。
输入格式为两行：
第一行：一个正整数 N（N < 10000）, 表示瓶子的数目
第二行：N 个正整数，用空格分开，表示瓶子目前的排列情况。
输出数据为一行一个正整数，表示至少交换多少次，才能完成排序。
例如，输入：
5
3 1 2 5 4
程序应该输出：
3
再例如，输入：
5
5 4 3 2 1
程序应该输出：
2

## 题目分析

使用贪心算法，当 i 号位置上的瓶子的编号不是 i 时，进行一次交换，将编号为 i 的瓶子交换到 i 号位置。

```c++
#include<iostream>
using namespace std;

int main()
{
	int n,a[10001];
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<n;i++) {
		if(a[i] != i) {
			for(int j=i+1;j<=n;j++) {
				if(a[j] == i) {
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
					sum++;
					break;
				}
			}
		}
	}
	cout<<sum<<endl;
	
	return 0;
}
```

