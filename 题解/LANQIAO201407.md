---
title: 蓝桥杯 2014年第五届省赛 C/C++ B组 07 六角填数
date: 2021-03-18 09:37:10
tags:
- 全排列
- 递归
- 深度优先搜索
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post5.jpg
---

## 题目描述

如图所示六角形中，填入 1 ~ 12 的数字。
使得每条直线上的数字之和都相同。
图中，已经替你填好了 3 个数字（1、3、8），请你计算星号位置所代表的数字是多少？
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/201407.jpg)

## 题目分析

使用全排列函数 next_permutation() 或使用递归。
注意六条直线上的数字之和（每个顶点计算了两次）等于整个六角形上的数字之和的两倍，所以每条直线上的数字之和为 (1 + 12) * 12 / 6 = 26。

### next_permutation()函数

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[9]={2,4,5,6,7,9,10,11,12};
	do {
		int sum1=1+a[0]+a[3]+a[5];
		int sum2=1+a[1]+a[4]+a[8];
		int sum3=a[5]+a[6]+a[7]+a[8];
		int sum4=3+a[6]+a[3]+8;
		int sum5=3+a[7]+a[4]+a[2];
		int sum6=8+a[0]+a[1]+a[2];
		if(sum1==26 && sum2==26 && sum3==26 && sum4==26 && sum5==26 && sum6==26) {
			cout<<a[3]<<endl;
			break;
		}
	} while(next_permutation(a,a+9));
	
	return 0;
}
```

### 递归

```c++
#include<iostream>
using namespace std;

int res[9]={0};
int a[9]={2,4,5,6,7,9,10,11,12};
int vis[9]={0};

void dfs(int n) {
	if(n == 9) {
		int sum1=1+res[0]+res[3]+res[5];
		int sum2=1+res[1]+res[4]+res[8];
		int sum3=res[5]+res[6]+res[7]+res[8];
		int sum4=3+res[6]+res[3]+8;
		int sum5=3+res[7]+res[4]+res[2];
		int sum6=8+res[0]+res[1]+res[2];
		if(sum1==26 && sum2==26 && sum3==26 && sum4==26 && sum5==26 && sum6==26) {
			cout<<res[3]<<endl;
		}
        return;
	}
	for(int i=0;i<9;i++) {
		if(vis[i] == 1) {
			continue;
		}
		vis[i]=1;
		res[n]=a[i];
		dfs(n+1);
		vis[i]=0;
	}
}

int main()
{
	dfs(0);
	
	return 0;
}
```

## 题目答案

**10**