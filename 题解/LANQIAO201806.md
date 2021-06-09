---
title: 蓝桥杯 2018年第九届省赛 C/C++ B组 06 递增三元组
date: 2021-04-11 16:11:53
tags:
- 哈希表
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post6.jpg
---

## 题目描述

给定三个整数数组
A = [A1, A2, ... AN]
B = [B1, B2, ... BN]
C = [C1, C2, ... CN]
请你统计有多少个三元组(i, j, k)满足：
1、 1 <= i, j, k <= N
2、 Ai < Bj < Ck
【输入格式】
第一行包含一个整数N。
第二行包含N个整数A1, A2, ... AN。
第三行包含N个整数B1, B2, ... BN。
第四行包含N个整数C1, C2, ... CN。
对于30%的数据，1 <= N <= 100
对于60%的数据，1 <= N <= 1000
对于100%的数据，1 <= N <= 100000，0 <= Ai, Bi, Ci <= 100000
【输出格式】
一个整数表示答案
【样例输入】
3
1 1 1
2 2 2
3 3 3
【样例输出】
27

## 题目分析

暴力只能通过 71% 的数据。
需要使用哈希表分别保存三个数组中每个整数出现的次数，若分别取自三个数组的三个整数 a < b < c，则
ans += num_a \* num_b \* num_c（num_a 为整数 a 在数组 A 中出现的次数）。

### 暴力

```c++
#include<iostream>
using namespace std;

int main()
{
	int n,abc[3][100000];
	cin>>n;
	for(int i=0;i<3;i++) {
		for(int j=0;j<n;j++) {
			cin>>abc[i][j];
		}
	}
	long long ans=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(abc[0][i] < abc[1][j]) {
				for(int k=0;k<n;k++) {
					if(abc[1][j] < abc[2][k]) {
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
```

### 哈希表

```c++
#include<iostream>
using namespace std;

int main()
{
	int n,t,abc[3][100001]={0},maxabc[3]={0};
	cin>>n;
	for(int i=0;i<3;i++) {
		for(int j=0;j<n;j++) {
			cin>>t;
			abc[i][t]++; //分别保存三个数组中每个整数出现的次数
			if(t > maxabc[i]) {
				maxabc[i]=t;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=maxabc[0];i++) {
		if(abc[0][i]) {
			for(int j=i+1;j<=maxabc[1];j++) {
				if(abc[1][j]) {
					for(int k=j+1;k<=maxabc[2];k++) {
						if(abc[2][k]) {
							ans+=abc[0][i]*abc[1][j]*abc[2][k];
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
    
	return 0;
}
```