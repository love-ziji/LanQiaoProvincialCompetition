---
title: 蓝桥杯 2016年第七届省赛 C/C++ B组 06 方格填数
date: 2021-03-27 19:55:46
tags:
- 全排列
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post1.jpg
---

## 题目描述

如下的 10 个格子
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/201606.jpg)
填入 0 ~ 9 的数字。
要求：连续的两个数字不能相邻。（左右、上下、对角都算相邻）
一共有多少种可能的填数方案？

## 题目分析

暴力即可，但要细心一点，对角相邻包括主对角相邻和副对角相邻。

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int sum=0,a[10]={0,1,2,3,4,5,6,7,8,9};
	do {
		if(abs(a[0]-a[1])!=1 && abs(a[0]-a[3])!=1 && abs(a[0]-a[4])!=1) {
			if(abs(a[1]-a[2])!=1 && abs(a[1]-a[3])!=1 && abs(a[1]-a[4])!=1 && abs(a[1]-a[5])!=1) {
				if(abs(a[2]-a[4])!=1 && abs(a[2]-a[5])!=1 && abs(a[2]-a[6])!=1) {
					if(abs(a[3]-a[4])!=1 && abs(a[3]-a[7])!=1) {
						if(abs(a[4]-a[5])!=1 && abs(a[4]-a[7])!=1 && abs(a[4]-a[8])!=1) {
							if(abs(a[5]-a[6])!=1 && abs(a[5]-a[7])!=1 
                               && abs(a[5]-a[8])!=1 && abs(a[5]-a[9])!=1) {
								if(abs(a[6]-a[8])!=1 && abs(a[6]-a[9])!=1) {
									if(abs(a[7]-a[8])!=1 && abs(a[8]-a[9])!=1) {
										sum++;	
									}
								}
							}
						}
					}
				}
			}
		}
	} while(next_permutation(a,a+10));
	cout<<sum<<endl;
	
	return 0;
}
```

## 题目答案

**1580**