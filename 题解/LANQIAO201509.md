---
title: 蓝桥杯 2015年第六届省赛 C/C++ B组 09 垒骰子
date: 2021-03-23 18:14:52
tags:
- 动态规划
- STL
- 矩阵快速幂
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post2.jpg
mathjax: true
---

## 题目描述

赌圣 atm 晚年迷恋上了垒骰子，就是把骰子一个垒在另一个上边，不能歪歪扭扭，要垒成方柱体。
经过长期观察，atm 发现了稳定骰子的奥秘：有些数字的面贴着会互相排斥！
我们先来规范一下骰子：1 的对面是 4，2 的对面是 5，3 的对面是 6。
假设有 m 组互斥现象，每组中的那两个数字的面紧贴在一起，骰子就不能稳定的垒起来。 
atm 想计算一下有多少种不同的可能的垒骰子方式。
两种垒骰子方式相同，当且仅当这两种方式中对应高度的骰子的对应数字的朝向都相同。
由于方案数可能过多，请输出模 10^9 + 7 的结果。
不要小看了 atm 的骰子数量哦～
「输入格式」
第一行两个整数 n m
n 表示骰子数目，接下来 m 行，每行两个整数 a b，表示 a 和 b 数字不能紧贴在一起。
「输出格式」
一行一个数，表示答案模 10^9 + 7 的结果。
「样例输入」
2 1
1 2
「样例输出」
544
「数据范围」
对于 30% 的数据：n <= 5
对于 60% 的数据：n <= 100
对于 100% 的数据：0 < n <= 10^9，m <= 36

## 题目分析

### 动态规划
使用动态规划，状态转移方程：
$dp[i][j]=\sum{dp[i-1][k]}$
其中$dp[i][j]$表示第 i 个骰子 j 面朝上的方案数，k 表示能与 j 面的对面紧贴的面
使用 vector 储存面与面的紧贴关系
仅使用动态规划只能通过 78% 的数据，需要使用矩阵快速幂

```c++
#include<iostream>
#include<vector>
using namespace std;

const int MOD=1e9+7;

int main()
{
	vector<int> can[7]; //can[i]存能与点数i紧贴的点数
	long long top[7],bottom[7]; //top[i]存第n层骰子以点数i为顶面的方案数，bottom[i]存第n层骰子以点数i为底面的方案数
	//初始化 
	for(int i=1;i<=6;i++) {
		top[i]=1; //第1层骰子以点数i为顶面的方案数为1
		for(int j=1;j<=6;j++) {
			can[i].push_back(j);
		}
	}
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++) { //删除不能紧贴的m组点
		cin>>a>>b;
		for(vector<int>::iterator it=can[a].begin();it!=can[a].end();it++) {
			if(*it == b) {
				can[a].erase(it);
				break;
			}
		}
		for(vector<int>::iterator it=can[b].begin();it!=can[b].end();it++) {
			if(*it == a) {
				can[b].erase(it);
				break;
			}
		}
	}
	long long k=4;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=6;j++) {
			bottom[j]=0;
			for(vector<int>::iterator it=can[j].begin();it!=can[j].end();it++) {
				bottom[j]+=top[*it]; //状态转移方程
			}
		}
		for(int j=1;j<=6;j++) {
			top[j]=bottom[(j+3)%6==0 ? 6 : (j+3)%6]%MOD;
		}
		k*=4;
		k%=MOD;
	}
	long long sum=0;
	for(int i=1;i<=6;i++) {
		sum+=top[i];
		sum%=MOD;
	}
	cout<<sum*k%MOD<<endl;
	
	return 0;
}
```

### 动态规划+矩阵快速幂

![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/201509.png)
其中 T 为转移矩阵，$T[i][j]$表示 i 面和 j 面的冲突关系，$A[k]$表示第 1 个骰子 k 面朝上的方案数，$B[k]$表示第 2 个骰子 k 面朝上的方案数。
[矩阵快速幂入门](https://www.jianshu.com/p/1c3f88f63dec)

```c++
#include<iostream>
using namespace std;

typedef long long int ll;
typedef struct {
	ll m[7][7];
} Mat;

const int MOD=1e9+7;

// 矩阵乘法 
Mat mul(Mat a,Mat b) {
	Mat c;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			c.m[i][j]=0;
			for(int k=1;k<=6;k++) {
				c.m[i][j]+=a.m[i][k]*b.m[k][j]%MOD;
				c.m[i][j]%=MOD;
			}
		}
	}
	return c;
}

// 矩阵快速幂 
Mat pow(Mat a,int n) {
	Mat r;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			r.m[i][j]=i==j ? 1 : 0;
		}
	}
	while(n) {
		if(n&1) {
			r=mul(a,r);
		}
		a=mul(a,a);
		n>>=1;
	}
	return r;
}

// 快速幂 
ll pow(ll a,int n) {
	ll r=1;
	while(n) {
		if(n&1) {
			r=r*a%MOD;
		}
		a=a*a%MOD;
		n>>=1;
	}
	return r;
}

int main()
{
	int n,m;
	cin>>n>>m;
	Mat dp;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			dp.m[i][j]=1;
		}
	}
	int a,b;
	for(int i=0;i<m;i++) { //构造转移矩阵（即冲突矩阵）
		cin>>a>>b;
		dp.m[a][(b+3)%6==0 ? 6 : (b+3)%6]=0;
		dp.m[b][(a+3)%6==0 ? 6 : (a+3)%6]=0;
	}
	dp=pow(dp,n-1);
	ll sum=0;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			sum+=dp.m[i][j];
			sum%=MOD;
		}
	}
	cout<<sum*pow(4,n)%MOD<<endl;
	
	return 0;
}
```

