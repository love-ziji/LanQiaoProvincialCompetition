---
title: 蓝桥杯 2016年第七届省赛 C/C++ B组 07 剪邮票
date: 2021-03-27 20:20:18
tags:
- 组合问题
- 深度优先搜索
- 连通块
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post2.jpg
---

## 题目描述

如【图1.jpg】, 有 12 张连在一起的 12 生肖的邮票。
现在你要从中剪下 5 张来，要求必须是连着的。（仅仅连接一个角不算相连）
比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。
请你计算，一共有多少种不同的剪取方法。
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2016071.jpg)
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2016072.jpg)
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2016073.jpg)

## 题目分析

首先枚举从 12 张邮票中剪下 5 张邮票的所有组合，然后使用深度优先搜索判断这 5 张邮票的连通性，注意从 4 和 8 向右走走不到 5 和 9，从 5 和 9 向左走走不到 4 和 8。

```c++
#include<iostream>
#include<cstring>
using namespace std;

int dis[4]={-1,1,-4,4},vis[13],num[5];
int n,sum=0;

void dfs(int a) {
	if(n == 5) {
		sum++;
		return;
	}
	for(int i=0;i<4;i++) {
		if(dis[i]==1 && (a==4 || a==8) || dis[i]==-1 && (a==5 || a==9)) {
			continue;
		}
		int t=a+dis[i];
		if(t>=1 && t<=12 && vis[t]==0 && (t==num[1] || t==num[2] || t==num[3] || t==num[4])) {
			vis[t]=1;
			n++;
			dfs(t);
		}
	}
}

int main()
{
	//12个数里选5个数出来的所有组合
	for(num[0]=1;num[0]<=12-4;num[0]++) {
		for(num[1]=num[0]+1;num[1]<=12-3;num[1]++) {
			for(num[2]=num[1]+1;num[2]<=12-2;num[2]++) {
				for(num[3]=num[2]+1;num[3]<=12-1;num[3]++) {
					for(num[4]=num[3]+1;num[4]<=12;num[4]++) {
						memset(vis,0,sizeof(vis));
						vis[num[0]]=1;
						n=1;
						dfs(num[0]);
					}
				}
			}
		}
	}
	cout<<sum<<endl;
	
	return 0;
}
```

## 题目答案

**116**

