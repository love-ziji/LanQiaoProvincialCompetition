---
title: 蓝桥杯 2016年第七届省赛 C/C++ B组 10 最大比例
date: 2021-03-27 21:09:33
tags:
- STL
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post5.jpg
---

## 题目描述

X 星球的某个大奖赛设了 M 级奖励。每个级别的奖金是一个正整数。
并且，相邻的两个级别间的比例是个固定值。
也就是说：所有级别的奖金数构成了一个等比数列。比如：
16, 24, 36, 54
其等比值为：3/2
现在，我们随机调查了一些获奖者的奖金数。
请你据此推算可能的最大的等比值。
输入格式：
第一行为数字 N (0 < N < 100)，表示接下的一行包含 N 个正整数
第二行 N 个正整数 Xi (Xi < 1000000000000)，用空格分开，每个整数表示调查到的某人的奖金数额
要求输出：
一个形如 A/B 的分数，要求A、B互质。表示可能的最大比例系数。
测试数据保证了输入格式正确，并且最大比例是存在的。
例如，输入：
3
1250 200 32
程序应该输出：
25/4
再例如，输入：
4
3125 32 32 200
程序应该输出：
5/2
再例如，输入：
3
549755813888 524288 2
程序应该输出：
4/1

## 题目分析

使用 set 保存调查到的某人的奖金数额 X<sub>i</sub> ，自动去重且从小到大排序。
然后使用辗转相除法计算出 X<sub>i</sub> 与 X<sub>i-1</sub> 的最大公约数，将 X<sub>i</sub> / X<sub>i-1</sub> 化为最简分数，分别保存分子和分母。
最后使用与辗转相除法类似的原理分别计算出分子和分母的公底数。

```c++
#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b) {
	return b ? gcd(b,a%b) : a;
}

ll gcd2(ll a,ll b) { //求a、b的公底数
	if(a == b) {
		return a;
	}
	else if(a > b) {
		return gcd2(b,a/b);
	}
	else {
		return gcd2(a,b/a);
	}
}

int main()
{
	set<ll> s; //set元素不能重复且自动从小到大排序
	ll n,t;
	cin>>n;
	for(ll i=0;i<n;i++) {
		cin>>t;
		s.insert(t);
	}
	vector<ll> up,down; //保存分子和分母 
	ll num1,num2,n2=0;
	for(set<ll>::iterator it=--s.end();it!=s.begin();) {
		num1=*it;
		num2=*(--it);
		t=gcd(num1,num2);
		up.push_back(num1/t);
		down.push_back(num2/t);
		n2++;
	}
	ll a=up[0],b=down[0];
	for(int i=1;i<n2;i++) {
		a=gcd2(a,up[i]);
		b=gcd2(b,down[i]);
	}
	cout<<a<<'/'<<b<<endl;
	
	return 0;
}
```

