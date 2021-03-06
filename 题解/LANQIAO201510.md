---
title: 蓝桥杯 2015年第六届省赛 C/C++ B组 10 生命之树
date: 2021-03-23 19:44:11
tags:
- 树形DP
- STL
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post3.jpg
mathjax: true
---

## 题目描述

在 X 森林里，上帝创建了生命之树。
他给每棵树的每个节点（叶子也称为一个节点）上，都标了一个整数，代表这个点的和谐值。
上帝要在这棵树内选出一个非空节点集 S，使得对于 S 中的任意两个点a, b，都存在一个点列 {a, v1, v2, ... , vk, b} 使得这个点列中的每个点都是 S 里面的元素，且序列中相邻两个点间有一条边相连。
在这个前提下，上帝要使得 S 中的点所对应的整数的和尽量大。
这个最大的和就是上帝给生命之树的评分。
经过 atm 的努力，他已经知道了上帝给每棵树上每个节点上的整数。但是由于 atm 不擅长计算，他不知道怎样有效的求评分。他需要你为他写一个程序来计算一棵树的分数。
「输入格式」
第一行一个整数 n 表示这棵树有 n 个节点。
第二行 n 个整数，依次表示每个节点的评分。
接下来 n-1 行，每行 2 个整数 u, v，表示存在一条 u 到 v 的边。由于这是一棵树，所以是不存在环的。
「输出格式」
输出一行一个数，表示上帝给这棵树的分数。
「样例输入」
5
1 -2 -3 4 5
4 2
3 1
1 2
2 5
「样例输出」
8
「数据范围」
对于 30% 的数据，n <= 10
对于 100% 的数据，0 < n <= 10^5，每个节点的评分的绝对值不超过10^6

## 题目分析

使用树形DP，状态转移方程：
$dp[i]=\sum{max(dp[j],0)+w[i]}$
其中$dp[i]$为选择了 i 节点的情况下的最大分数，j 为 i 的子节点，w[i] 为 i 节点的权值
使用vector储存邻接矩阵

```c++
#include<iostream>
#include<vector>
using namespace std;

const int N=100001;

int vis[N]={0};
long long d[N],ans=-1e6;
vector<int> node[N-1]; //邻接矩阵

void dfs(int u) {
	vis[u]=1;
	for(int i=0;i<node[u].size();i++) {
		if(!vis[node[u][i]]) {
			dfs(node[u][i]);
			if(d[node[u][i]] > 0) {
				d[u]+=d[node[u][i]]; //状态转移方程 
			}
		}
	}
	ans=max(ans,d[u]);
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>d[i];
	}
	int u,v;
	for(int i=0;i<n-1;i++) {
		cin>>u>>v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	dfs(u);
	cout<<ans<<endl;
	
	return 0;
}
```

