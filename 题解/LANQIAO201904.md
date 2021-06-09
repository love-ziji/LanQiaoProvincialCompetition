---
title: 蓝桥杯 2019年第十届省赛 C/C++ B组 D 数的分解
date: 2021-04-12 16:14:02
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post5.jpg
---

## 题目描述

把 2019 分解成 3 个各不相同的正整数之和，并且要求每个正整数都不包含数字 2 和 4，一共有多少种不同的分解方法？
注意交换 3 个整数的顺序被视为同一种方法，例如 1000 + 1001 + 18 和 1001 + 1000 + 18 被视为同一种。

## 题目分析

三层循环即可，保证 3 个整数 i < j < k 即可保证不重复。
优化：可将三层循环变成二层循环，k = 2019 - i - j，第二层循环时使用 j < 2019 - i - j 保证 j < k。

```c++
#include<iostream>
using namespace std;

int f(int n) {
	while(n) {
		if(n%10==2 || n%10==4) {
			return 0;
		}
		n/=10;
	}
	return 1;
}

int main()
{
	int res=0;
	for(int i=1;i<=2019-2;i++) {
		if(f(i)) {
			for(int j=i+1;j<2019-i-j;j++) {
				if(f(j) && f(2019-i-j)) {
					res++;
				}
			}
		}
	}
	cout<<res<<endl;
	
	return 0;
}
```

## 题目答案

**40785**