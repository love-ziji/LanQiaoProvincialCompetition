---
title: 蓝桥杯 2015年第六届省赛 C/C++ B组 08 移动距离
date: 2021-03-23 17:15:04
tags:
- 坐标计算
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post1.jpg
---

## 题目描述

X 星球居民小区的楼房全是一样的，并且按矩阵样式排列。其楼房的编号为 1, 2, 3 ...
当排满一行时，从下一行相邻的楼往反方向排号。
比如：当小区排号宽度为6时，开始情形如下：
1 2 3 4 5 6
12 11 10 9 8 7
13 14 15 ......
我们的问题是：已知了两个楼号 m 和 n，需要求出它们之间的最短移动距离（不能斜线方向移动）
输入为 3 个整数w m n，空格分开，都在 1 到 10000 范围内
w 为排号宽度，m, n为待计算的楼号。
要求输出一个整数，表示m, n两楼间最短移动距离。
例如，用户输入：
6 8 2
则，程序应该输出：
4
再例如，用户输入：
4 7 20
则，程序应该输出：
5

## 题目分析

横坐标 x&ensp;&ensp;=&ensp;m / w
纵坐标 y1&ensp;=&ensp;( m % w ) == 0 ? w : m % w //正向排号
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; y2&ensp;=&ensp;w - y1 + 1 //反向排号

```c++
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int w,d[2][3];
	cin>>w>>d[0][0]>>d[1][0];
	for(int i=0;i<2;i++) {
		d[i][1]=d[i][0]/w; //计算x坐标
		//计算y坐标
		int t=(d[i][0]%w)==0?w:d[i][0]%w;
		if(d[i][1]%2 == 0) {
			d[i][2]=t; //正向排号
		}
		else {
			d[i][2]=w-t+1; //反向排号
		}
	}
	cout<<abs(d[0][1]-d[1][1])+abs(d[0][2]-d[1][2]); 
	
	return 0;
}
```

