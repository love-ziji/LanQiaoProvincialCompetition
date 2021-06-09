---
title: 蓝桥杯 2017年第八届省赛 C/C++ B组 04 方格分割
date: 2021-03-28 16:19:23
tags:
- 深度优先搜索
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post3.jpg
---

## 题目描述

6 x 6 的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。
如图：p1.png, p2.png, p3.png就是可行的分割法。
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2017041.1.png)
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2017042.1.png)
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2017043.1.png)
试计算：
包括这 3 种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

## 题目分析

使用深度优先搜索算法，从方格中心点 (3, 3) 出发， 每当向某个方向剪一个单位长度时，对称的方向也要剪一个单位长度，到达边界时停止。
注意旋转对称的属于同一种分割法，所以最后的结果要除以 4。

```c++
#include<iostream>
using namespace std;

int vis[7][7]={0};
int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans=0;

void dfs(int x,int y) {
	if(x==0 || y==0 || x==6 || y==6) {
		ans++;
		return;
	}
	for(int i=0;i<4;i++) {
		int tx=x+dis[i][0];
		int ty=y+dis[i][1];
		if(!vis[tx][ty]) {
			vis[tx][ty]=1;
			vis[6-tx][6-ty]=1;
			dfs(tx,ty);
			vis[tx][ty]=0;
			vis[6-tx][6-ty]=0;
		}
	}
}

int main()
{
	vis[3][3]=1;
	dfs(3,3);
	cout<<ans/4<<endl;
	
	return 0;
}
```

## 题目答案

**509**