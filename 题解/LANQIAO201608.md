---
title: 蓝桥杯 2016年第七届省赛 C/C++ B组 08 四平方和
date: 2021-03-27 20:40:08
tags:
- 暴力
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post3.jpg
---

## 题目描述

四平方和定理，又称为拉格朗日定理：
每个正整数都可以表示为至多 4 个正整数的平方和。
如果把 0 包括进去，就正好可以表示为 4 个数的平方和。
比如：
5 = 0^2 + 0^2 + 1^2 + 2^2
7 = 1^2 + 1^2 + 1^2 + 2^2
（^符号表示乘方的意思）
对于一个给定的正整数，可能存在多种平方和的表示法。
要求你对 4 个数排序：0 <= a <= b <= c <= d
并对所有的可能表示法按 a,b,c,d 为联合主键升序排列，最后输出第一个表示法
程序输入为一个正整数 N (N < 5000000)
要求输出 4 个非负整数，按从小到大排序，中间用空格分开
例如，输入：
5
则程序应该输出：
0 0 1 2
再例如，输入：
12
则程序应该输出：
0 2 2 2
再例如，输入：
773535
则程序应该输出：
1 1 267 838

## 题目分析

暴力使用四层循环只能通过 78% 的数据，将四层循环改为三层循环即可。

```c++
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int a=0;a<=sqrt(n);a++) {
		for(int b=a;b<=sqrt(n);b++) {
			if(a*a+b*b <= n) {
				for(int c=b;c<=sqrt(n);c++) {
					int t=a*a+b*b+c*c;
					if(t <= n) {
						int d=sqrt(n-t); //四层循环改为三层循环
						if(t+d*d == n) {
							cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
							return 0;
						}
					}
				}
			}
		}
	}
	
	return 0;
}
```

