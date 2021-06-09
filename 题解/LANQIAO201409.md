---
title: 蓝桥杯 2014年第五届省赛 C/C++ B组 09 地宫取宝
date: 2021-03-19 09:01:54
tags:
- 递归
- 深度优先搜索
- 记忆化搜索
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post2.jpg
---

## 题目描述

X 国王有一个地宫宝库。是 n x m 个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。地宫的入口在左上角，出口在右下角。小明被带到地宫的入口，国王要求他只能向右或向下行走。走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。当小明走到出口时，如果他手中的宝贝恰好是 k 件，则这些宝贝就可以送给小明。请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这 k 件宝贝。
输入一行 3 个整数，用空格分开：n m k(1 <= n, m <= 50，1 <= k <= 12)
接下来有 n 行数据，每行有 m 个整数 Ci (0 <= Ci <= 12)代表这个格子上的宝物的价值。
要求输出一个整数，表示正好取 k 个宝贝的行动方案数。该数字可能很大，输出它对 1000000007 取模的结果。
例如，输入：
2 2 2
1 2
2 1
程序应该输出：
2
再例如，输入：
2 3 2
1 2 3
2 1 5
程序应该输出：
14

## 题目分析

使用递归，但若仅使用深度优先搜索算法，只能通过 50% 的数据，需要使用记忆化搜索。

### 深度优先搜索

```c++
#include<iostream>
using namespace std;

int n,m,k,sum=0,mapVal[50][50];

void dfs(int i,int j,int maxVal,int num) {
	if(i==n-1 && j==m-1) {
	    //走到出口时手中已有k件宝贝 或 手中有k-1件宝贝且出口格子中的宝贝价值比小明手中任意宝贝价值都大
		if(num==k || maxVal<mapVal[i][j]&&num==k-1) {
			sum++;
			sum%=1000000007;
		}
	}
	if(i < n-1) { //能够向下走 
		if(maxVal < mapVal[i][j]) {
			dfs(i+1,j,mapVal[i][j],num+1); //拿起宝贝向下走 
		}
		dfs(i+1,j,maxVal,num); //不拿起宝贝向下走 
	}
	if(j < m-1) { //能够向右走 
		if(maxVal < mapVal[i][j]) {
			dfs(i,j+1,mapVal[i][j],num+1); //拿起宝贝向右走 
		}
		dfs(i,j+1,maxVal,num); //不拿起宝贝向右走 
	}
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>mapVal[i][j];
		}
	}
	dfs(0,0,-1,0);
	cout<<sum<<endl;
	
	return 0;
}
```

### 深度优先搜索+记忆化搜索

```c++
#include<iostream>
#include<cstring>
using namespace std;

int n,m,k,mapVal[50][50],dp[50][50][13][13]; 

int dfs(int i,int j,int maxVal,int num) {
	if(dp[i][j][maxVal+1][num] != -1) { //若不等于-1，则表示已搜索过
		return dp[i][j][maxVal+1][num];
	}
	if(i==n-1 && j==m-1) {
		if(num==k || maxVal<mapVal[i][j]&&num==k-1) {
			return dp[i][j][maxVal+1][num]=1;
		} else {
			return dp[i][j][maxVal+1][num]=0;
		}
	}
	long long sum=0;
	if(i < n-1) {
		if(maxVal < mapVal[i][j]) {
			sum+=dfs(i+1,j,mapVal[i][j],num+1);
		}
		sum+=dfs(i+1,j,maxVal,num);
	}
	if(j < m-1) {
		if(maxVal < mapVal[i][j]) {
			sum+=dfs(i,j+1,mapVal[i][j],num+1);
		}
		sum+=dfs(i,j+1,maxVal,num);
	}
	//宝贝价值可能为0，所以手中已有宝贝的最大价值初始值为-1
	//数组下标最小值为0，所以是maxVal+1
	return dp[i][j][maxVal+1][num]=sum%1000000007;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>mapVal[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,0,-1,0)<<endl;
	
	return 0;
}
```

