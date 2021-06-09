---
title: 蓝桥杯 2017年第八届省赛 C/C++ B组 10 k倍区间
date: 2021-03-29 10:23:42
tags:
- 前缀和
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post2.jpg
---

## 题目描述

给定一个长度为 N 的数列，A1, A2, ... , AN，如果其中一段连续的子序列Ai, Ai+1, ... , Aj (i <= j) 之和是 K 的倍数，我们就称这个区间[i, j]是 K 倍区间。
你能求出数列中总共有多少个 K 倍区间吗？
输入
第一行包含两个整数 N 和 K (1 <= N, K <= 100000)
以下 N 行每行包含一个整数 Ai (1 <= Ai <= 100000)
输出
输出一个整数，代表 K 倍区间的数目。
例如，输入：
5 2
1
2
3
4
5
程序应该输出：
6

## 题目分析

先计算前缀和 S<sub>i</sub>，因为若S<sub>i</sub> % K == S<sub>j</sub> % K，则区间[i, j]是 K 倍区间，所以以除以 K 的余数将 S<sub>i</sub> 分类，并将每个分类包含的 S<sub>i</sub> 的个数保存为N<sub>j</sub>（j 为除以 K 的余数），则每个分类 K 倍区间的个数为 N<sub>j</sub> * (N<sub>j</sub> - 1) / 2，注意最后要加上余数为 0 的个数。

```c++
#include<iostream>
using namespace std;
const int N=100000;

int main()
{
	int n,k,a[N+1];
	long long s[N+1]={0},num[N]={0};
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		num[s[i]%k]++;
	}
	long long ans=num[0];
	for(int i=0;i<k;i++) {
		if(num[i] > 1) {
			ans+=num[i]*(num[i]-1)/2;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
```

