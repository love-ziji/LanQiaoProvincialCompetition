---
title: 蓝桥杯 2017年第八届省赛 C/C++ B组 09 分巧克力
date: 2021-03-29 10:09:43
tags:
- 二分法
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post1.jpg
---

## 题目描述

儿童节那天有 K 位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。
小明一共有 N 块巧克力，其中第 i 块是 Hi x Wi 的方格组成的长方形。
为了公平起见，小明需要从这 N 块巧克力中切出 K 块巧克力分给小朋友们。切出的巧克力需要满足：
1、形状是正方形，边长是整数
2、大小相同
例如一块 6 x 5 的巧克力可以切出 6 块 2 x 2 的巧克力或者 2 块 3 x 3 的巧克力。
当然小朋友们都希望得到的巧克力尽可能大，你能帮小 Hi 计算出最大的边长是多少么？
输入
第一行包含两个整数 N 和 K (1 <= N, K <= 100000)
以下 N 行每行包含两个整数 Hi 和 Wi (1 <= Hi, Wi <= 100000)
输入保证每位小朋友至少能获得一块 1 x 1 的巧克力。
输出
输出切出的正方形巧克力最大可能的边长。
样例输入：
2 10
6 5
5 6
样例输出：
2

## 题目分析

需要使用二分法，否则只能通过 78% 的数据。

### 未使用二分法

```c++
#include<iostream>
using namespace std;
const int N=100000;

int main()
{
	int n,k,h,w,maxLen=0,num[N+1]={0};
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>h>>w;
		maxLen=max(maxLen,min(h,w));
		for(int j=1;j<=min(h,w);j++) {
			num[j]+=(h/j)*(w/j);
		}
	}
	for(int i=maxLen;i>0;i--) {
		if(num[i] >= k) {
			cout<<i<<endl;
			break;
		}
	}
	
	return 0;
}
```

### 使用二分法

```c++
#include<iostream>
using namespace std;

const int N=100000;
int n,k,h[N],w[N],maxLen=0;

bool f(int len) {
	int num=0;
	for(int i=0;i<n;i++) {
		num+=(h[i]/len)*(w[i]/len);
	}
	return num>=k;
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>h[i]>>w[i];
		maxLen=max(maxLen,min(h[i],w[i]));
	}
	int L=1,R=maxLen,Mid;
	while(L<=R) {
		Mid=(L+R)/2;
		f(Mid) ? L=Mid+1 : R=Mid-1;
	}
	cout<<L-1<<endl;
	
	return 0;
}
```

