---
title: 蓝桥杯 2019年第十届省赛 C/C++ B组 C 数列求值
date: 2021-04-12 16:00:25
tags:
- 矩阵快速幂
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post4.jpg
---

## 题目描述

给定数列 1, 1, 1, 3, 5, 9, 17, …，从第 4 项开始，每项都是前 3 项的和。求第 20190324 项的最后 4 位数字。

## 题目分析

类似斐波那契数列，用数组保存三项值，通过对 3 取余依次计算下一项并进行替换。

```c++
#include<iostream>
using namespace std;

int main()
{
	int a[3]={1,1,1};
	int index=3;
	while(index < 20190324) {
		a[index%3]=(a[0]+a[1]+a[2])%10000;
		index++;
	}
	cout<<a[(index-1)%3]<<endl;
	
	return 0;
}
```

觉得自己矩阵快速幂还没有完全掌握，所以又用矩阵快速幂做了一遍。参考：[矩阵快速幂例题](https://blog.pzijigame.com/2021-03-23-LANQIAO201509.html)

```c++
#include<iostream>
#include<cstring>
using namespace std;
const int MOD=10000;

void mul(int a[3][3],int b[3][3]) {
	int t[3][3]={0};
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			for(int k=0;k<3;k++) {
				t[i][j]=(t[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
			}
		}
	}
	memcpy(a,t,sizeof(t));
}

int main()
{
	int t[3][3]={{0,1,0},{0,0,1},{1,1,1}},res[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	int n=20190324-3;
	while(n) {
		if(n&1) {
			mul(res,t);
		}
		mul(t,t);
		n>>=1;
	}
	cout<<(res[2][0]+res[2][1]+res[2][2])%MOD<<endl;
	
	return 0;
}
```

## 题目答案

**4659**