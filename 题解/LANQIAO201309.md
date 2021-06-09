---
title: 蓝桥杯 2013年第四届省赛 C/C++ B组 09 带分数
date: 2021-03-13 16:31:41
tags:
- 全排列
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post2.jpg
---

## 题目描述

100 可以表示为带分数的形式：100 = 3 + 69258 / 714
还可以表示为：100 = 82 + 3546 / 197
注意特征：带分数中，数字 1 - 9 分别出现且只出现一次（不包含 0）。
类似这样的带分数，100 有 11 种表示法。
题目要求：
从标准输入读入一个正整数 N  (N < 1000*1000)
程序输出该数字用数码 1 - 9 不重复不遗漏地组成带分数表示的全部种数。
注意：不要求输出每个表示，只统计有多少表示法！
例如：
用户输入：
100
程序输出：
11
再例如：
用户输入：
105
程序输出：
6

## 题目分析

全排列问题，使用next_permutation()函数（使用do-while结构，否则会少原始情况），然后切分为a、b、c三个数，比较 N 与 a + b / c 是否相等。
注意 a 的位数最大为 7 位，b 的位数一定大于等于 c 的位数且 c 整除 b。

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int arr[9]={1,2,3,4,5,6,7,8,9};

int getNum(int x,int y) { //由数组求出该数 
	int num=0;
	for(int i=x;i<=y;i++) {
		num=num*10+arr[i];
	}
	return num;
}

int main()
{
	int n,sum=0;
	cin>>n;
	do {
		for(int i=0;i<7;i++) { //a的位数最大为7位 
			for(int j=i+1;j<8;j++) { //c的位数不能为0
				if(j-i >= 8-j) {
					int a=getNum(0,i); //a=arr[0]...arr[i]
					int b=getNum(i+1,j); //b=arr[i+1]...arr[j]
					int c=getNum(j+1,8); //c=arr[j+1]..a[8]
					if(b%c==0 && a+b/c==n) {
						sum++;
					}
				}
			}
		}
	} while(next_permutation(arr,arr+9));
	cout<<sum<<endl;
	
	return 0;
}
```

