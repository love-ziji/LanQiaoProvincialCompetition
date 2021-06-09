---
title: 蓝桥杯 2015年第六届省赛 C/C++ B组 07 牌型种数
date: 2021-03-23 09:10:01
tags:
- 递归
- 动态规划
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post5.jpg
mathjax: true
---

## 题目描述

小明被劫持到 X 赌城，被迫与其他 3 人玩牌。
一副扑克牌（去掉大小王牌，共 52 张），均匀发给 4 个人，每个人 13 张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？
请填写该整数，不要填写任何多余的内容或说明文字。 

## 题目分析

### 暴力枚举

```c++
#include<iostream>
using namespace std;

int main()
{
	int sum=0;
	for(int a=0;a<=4;a++)
		for(int b=0;b<=4;b++)
			for(int c=0;c<=4;c++)
				for(int d=0;d<=4;d++)
					for(int e=0;e<=4;e++)
						for(int f=0;f<=4;f++)
							for(int g=0;g<=4;g++)
								for(int h=0;h<=4;h++)
									for(int i=0;i<=4;i++)
										for(int j=0;j<=4;j++)
											for(int k=0;k<=4;k++)
												for(int m=0;m<=4;m++)
													for(int n=0;n<=4;n++)
														if(a+b+c+d+e+f+g+h+i+j+k+m+n == 13)
															sum++;
	cout<<sum<<endl;
	
	return 0;
}
```

### 递归

```c++
#include<iostream>
using namespace std;

int res=0,a[13]={0};

void fun(int n) {
	if(n == 13) {
		int sum=0;
		for(int i=0;i<13;i++) {
			sum+=a[i];
		}
		if(sum == 13) {
			res++;
		}
		return;
	}
	for(int i=0;i<=4;i++) {
		a[n]=i;
		fun(n+1);
	}
} 

int main()
{
	fun(0);
	cout<<res<<endl;
	
	return 0;	
}
```

### 动态规划

状态转移方程：
$dp[i][j]$ = //选完 i 点数的牌，剩余 j 张牌待选时的组合数
$dp[i-1][j]$ //上一点数的牌没有选
\+ $dp[i-1][j+1]$ //上一点数的牌选了一张
\+ $dp[i-1][j+2]$ //上一点数的牌选了两张
\+ $dp[i-1][j+3]$ //上一点数的牌选了三张
\+ $dp[i-1][j+4]$ //上一点数的牌选了四张

```c++
#include<iostream>
using namespace std;

int main()
{
	int dp[14][14]={0}; //dp[i][j]：选完i点数的牌，剩余j张牌待选时的组合数
	for(int i=9;i<=13;i++) {
		dp[1][i]=1;
	}
	for(int i=2;i<=13;i++) {
		for(int j=0;j<=13;j++) {
			//状态转移方程 
			for(int k=0;k<=4&&j+k<=13;k++) {
				dp[i][j]+=dp[i-1][j+k];
			}
		}
	}
	cout<<dp[13][0]<<endl;
	
	return 0;
}
```

## 题目答案

**3598180**

