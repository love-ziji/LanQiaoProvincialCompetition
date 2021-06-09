---
title: 蓝桥杯 2017年第八届省赛 C/C++ B组 02 等差素数列
date: 2021-03-28 15:50:48
tags:
- 暴力
- 素数
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post1.jpg
---

## 题目描述

2, 3, 5, 7, 11, 13, .... 是素数序列。
类似：7, 37, 67, 97, 127, 157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为 30，长度为 6。
2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！
有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：
长度为 10 的等差素数列，其公差最小值是多少？

## 题目分析

三层循环暴力即可，注意先打素数表，可大大提高程序效率。

```c++
#include<iostream>
using namespace std;

int isPrime(int n) {
	for(int i=2;i*i<=n;i++) {
		if(n%i == 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int prime[10001]={0,0};
	for(int i=2;i<=10000;i++) { //素数表
		prime[i]=isPrime(i);
	}
	for(int i=1;i<=1000;i++) { //循环公差
		for(int j=2;j<=1000;j++) { //循环首项
			if(prime[j] == 1) {
				int f=1;
				for(int k=1;k<=9;k++) {
					if(prime[j+k*i] == 0) {
						f=0;
						break;
					}
				}
				if(f == 1) {
					cout<<i<<endl;	
				}
			}
		}
	}
	
	return 0;
}
```

## 题目答案

**210**