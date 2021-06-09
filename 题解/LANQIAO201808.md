---
title: 蓝桥杯 2018年第九届省赛 C/C++ B组 08 日志统计
date: 2021-04-11 19:46:37
tags:
- STL
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post8.jpg
---

## 题目描述

小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有 N 行。其中每一行的格式是：
ts id
表示在 ts 时刻编号 id 的帖子收到一个"赞"。
现在小明想统计有哪些帖子曾经是"热帖"。如果一个帖子曾在任意一个长度为 D 的时间段内收到不少于 K 个赞，小明就认为这个帖子曾是"热帖"。
具体来说，如果存在某个时刻 T 满足该帖在[T, T+D)这段时间内（注意是左闭右开区间）收到不少于 K 个赞，该帖就曾是"热帖"。
给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。
【输入格式】
第一行包含三个整数N、D 和K。
以下 N 行每行一条日志，包含两个整数 ts 和 id。
对于 50% 的数据，1 <= K <= N <= 1000
对于 100% 的数据，1 <= K <= N <= 100000，0 <= ts <= 100000，0 <= id <= 100000
【输出格式】
按从小到大的顺序输出热帖 id。每个 id 一行。
【输入样例】
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3
【输出样例】
1
3

## 题目分析

注意数据结构的合理选取及使用，使用结构体保存帖子的 id 和收到的赞的数量，为什么不直接用一维数组保存帖子的 id 和收到的赞的数量？因为要以收到的赞的数量对帖子排序，使用一维数组会丢失帖子的 id；使用动态二维数组 vector< vector\<int\> > 保存每个帖子收到赞的时间，提高空间效率；使用 set 保存热帖 id，自动排序。
该题输出的行数较大，使用 '\n' 代替 endl 可以大大提高效率。输入输出使用较频繁时，尽量使用C语言的输入输出，C语言的输入输出更高效！

```c++
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int N=100001;

// 帖子结构体，保存帖子的id和收到的赞的数量 
typedef struct {
	int id,num;
} Log;

bool compare(Log a,Log b) {
	return a.num>b.num;
}

int main()
{
	int n,d,k;
	Log log[N];
	for(int i=0;i<N;i++) {
		log[i].id=i;
		log[i].num=0;
	}
	vector< vector<int> > time(N); //保存每个帖子收到赞的时间 
	set<int> ans; //保存热帖id，使用set自动排序 
	cin>>n>>d>>k;
	int ts,id,maxid=0;
	for(int i=0;i<n;i++) {
		cin>>ts>>id;
		if(id > maxid) {
			maxid=id;
		}
		log[id].num++;
		time[id].push_back(ts);
	}
	sort(log,log+maxid+1,compare); //以收到的赞的数量对帖子排序 
	for(int i=0;i<=maxid && log[i].num>=k;i++) {
		int f=0;
		sort(time[log[i].id].begin(),time[log[i].id].end()); //将收到赞的时间排序 
		for(int j=0;j<time[log[i].id].size();j++) {
			int q=j;
			while(time[log[i].id][q]-time[log[i].id][j]<d && q<time[log[i].id].size()) {
				if(q-j+1>=k) { //判断是否是热帖 
					ans.insert(log[i].id);
					f=1;
					break;
				}
				q++;
			}
			if(f) {
				break;
			}
		}
	}
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++) {
		cout<<*it<<'\n'; //用'\n'代替endl提高效率 
	}
	
	return 0;
}
```