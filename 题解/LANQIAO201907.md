---
title: 蓝桥杯 2019年第十届省赛 C/C++ B组 G 完全二叉树的权值
date: 2021-04-12 16:46:09
tags:
- 树
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post7.jpg
---

## 题目描述

给定一棵包含 N 个节点的完全二叉树，树上每个节点都有一个权值，按从上到下、从左到右的顺序依次是 A1, A2, · · · AN，如下图所示：
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/201907.png)
现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点权值之和最大？如果有多个深度的权值和同为最大，请你输出其中最小的深度。
注：根的深度是 1。
【输入格式】
第一行包含一个整数 N。
第二行包含 N 个整数 A1, A2, · · · AN。
【输出格式】
输出一个整数代表答案。
【样例输入】
7
1 6 5 4 3 2 1
【样例输出】
2
【评测用例规模与约定】
对于所有评测用例，1 ≤ N ≤ 100000，−100000 ≤ Ai ≤ 100000。

## 题目分析

完全二叉树深度 = h 的节点个数为 2<sup>h-1</sup>，根的深度是 1。

```c++
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int n,a[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	vector<int> res;
	int p=0,q=0;
	while(p<n) {
		int sum=0;
		for(int i=0;i<pow(2,q)&&p<n;i++) {
			sum+=a[p++];
		}
		res.push_back(sum);
		q++;
	}
	int maxIndex=0;
	for(int i=1;i<res.size();i++) {
		if(res[i]>res[maxIndex]) {
			maxIndex=i;
		}
	}
	cout<<maxIndex+1<<endl;
	
	return 0;
}
```