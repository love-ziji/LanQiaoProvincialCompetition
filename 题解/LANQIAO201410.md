---
title: 蓝桥杯 2014年第五届省赛 C/C++ B组 10 小朋友排队
date: 2021-03-19 09:54:20
tags:
- 逆序对
- 树状数组
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post3.jpg
---

## 题目描述

n 个小朋友站成一排。现在要把他们按身高从低到高的顺序排列，但是每次只能交换位置相邻的两个小朋友。每个小朋友都有一个不高兴的程度。开始的时候，所有小朋友的不高兴程度都是 0。如果某个小朋友第一次被要求交换，则他的不高兴程度增加 1，如果第二次要求他交换，则他的不高兴程度增加 2（即不高兴程度为 3），依次类推。当要求某个小朋友第 k 次交换时，他的不高兴程度增加 k。请问，要让所有小朋友按从低到高排队，他们的不高兴程度之和最小是多少。如果有两个小朋友身高一样，则他们谁站在谁前面是没有关系的。
输入的第一行包含一个整数 n，表示小朋友的个数。
第二行包含 n 个整数 H1 H2 … Hn，分别表示每个小朋友的身高。
输出一行，包含一个整数，表示小朋友的不高兴程度和的最小值。
例如，输入：
3
3 2 1
程序应该输出：
9
首先交换身高为 3 和 2 的小朋友，再交换身高为 3 和 1 的小朋友，再交换身高为 2 和 1 的小朋友，每个小朋友的不高兴程度都是 3，总和为 9。
对于10%的数据，1 <= n <= 10；
对于30%的数据，1 <= n <= 1000；
对于50%的数据，1 <= n <= 10000；
对于100%的数据，1 <= n <= 100000，0 <= Hi <= 1000000。

## 题目分析

小朋友的最小交换次数为小朋友的身高在逆序对（右边比其小或左边比其大）中出现的次数。
暴力枚举计算逆序对，只能通过 55% 的数据，需要使用树状数组。[树状数组入门](https://blog.csdn.net/Small_Orange_glory/article/details/81290634)

### 暴力枚举

```c++
#include<iostream>
using namespace std;

int main()
{
	int n,h[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>h[i];
	}
	int numR,numL;
	long long sum=0;
	for(int i=0;i<n;i++) {
		numR=numL=0;
		for(int j=i+1;j<n;j++) {
			if(h[j] < h[i]) {
				numR++; //右边比起小 
			}
		}
		for(int j=i-1;j>=0;j--) {
			if(h[j] > h[i]) {
				numL++; //左边比起大 
			}
		}
		sum+=(1+numR+numL)*(numR+numL)/2;
	}
	cout<<sum<<endl;
	
	return 0;
}
```

### 树状数组

```c++
#include<iostream>
#include<cstring>
using namespace std;
#define lowbit(x) x&(-x) //lowbit(x)=2^k,k为x的二进制中从最低位到高位连续零的长度

int maxh=-1,tree[1000001]; //树状数组下标为身高，原数组保存每个身高的小朋友个数

void update(int x,int val) { //更新树状数组
	while(x <= maxh+1) {
		tree[x]+=val;
		x+=lowbit(x);
	}
}

int getsum(int x) { //通过树状数组计算原数组前x项和，这里即为小于等于h[i]的数据个数
	int sum=0;
	while(x > 0) {
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}

int main()
{
	int n,h[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>h[i];
		maxh=max(maxh,h[i]);
	}
	long long swap[100000];
	for(int i=0;i<n;i++) {
		update(h[i]+1,1); //为什么是h[i]+1？树状数组下标从1开始，而h[i]可能为0
		swap[i]=i+1-getsum(h[i]+1); //计算左边比其大的数据个数，等于左边数据总个数-小于等于其的数据个数
	}
	memset(tree,0,sizeof(tree));
	for(int i=n-1;i>=0;i--) {
		update(h[i]+1,1);
		swap[i]+=getsum(h[i]); //计算右边比其小的数据个数
	}
	long long res=0;
	for(int i=0;i<n;i++) {
		res+=(1+swap[i])*swap[i]/2;
	}
	cout<<res<<endl;
	
	return 0;
}
```

