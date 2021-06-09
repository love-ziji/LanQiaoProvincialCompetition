---
title: 蓝桥杯 2017年第八届省赛 C/C++ B组 03 承压计算
date: 2021-03-28 15:58:52
tags:
- 找规律
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post2.jpg
mathjax: true
---

## 题目描述

X 星球的高科技实验室中整齐地堆放着某批珍贵金属原料。
每块金属原料的外形、尺寸完全一致，但重量不同。
金属材料被严格地堆放成金字塔形。

![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/201703.png)
其中的数字代表金属块的重量（计量单位较大）。
最下一层的 X 代表 30 台极高精度的电子秤。
假设每块原料的重量都十分精确地平均落在下方的两个金属块上，
最后，所有的金属块的重量都严格精确地平分落在最底层的电子秤上。
电子秤的计量单位很小，所以显示的数字很大。
工作人员发现，其中读数最小的电子秤的示数为：2086458231
请你推算出：读数最大的电子秤的示数为多少？

## 题目分析

规律比较简单：
$a[i+1][j]=a[i+1][j]+a[i][j]/2$
$a[i+1][j+1]=a[i+1][j+1]+a[i][j]/2$
难点在于金属块重量的计量单位和电子秤的计量单位不同，差了一个倍数。
这个倍数我也是猜测出来的，层数增加一层，金属块的重量就要除以 2，为了保证能整除，所以这个倍数为 2^29。

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long n=1,a[30][30]={0};
	for(int i=0;i<29;i++) {
		n<<=1;
	}
	for(int i=0;i<29;i++) {
		for(int j=0;j<=i;j++) {
			cin>>a[i][j];
			a[i][j]*=n;
		}
	}
	for(int i=0;i<29;i++) {
		for(int j=0;j<=i;j++) {
			long long t=a[i][j]/2;
			a[i+1][j]+=t;
			a[i+1][j+1]+=t;
		}
	}
	sort(a[29],a[29]+30);
//	cout<<a[29][0]<<endl;
	cout<<a[29][29]<<endl;
	
	return 0;
}
```

## 题目答案

**72665192664**

