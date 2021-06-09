---
title: 蓝桥杯 2018年第九届省赛 C/C++ B组 07 螺旋折线
date: 2021-04-11 17:02:31
tags:
- 模拟
- 找规律
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post7.jpg
---

## 题目描述

![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2018071.png)
如图所示的螺旋折线经过平面上所有整点恰好一次。
对于整点(X, Y)，我们定义它到原点的距离dis(X, Y)是从原点到(X, Y)的螺旋折线段的长度。
例如dis(0, 1) = 3, dis(-2, -1) = 9
给出整点坐标(X, Y)，你能计算出dis(X, Y)吗？
【输入格式】
X和Y
对于40%的数据, -1000 <= X, Y <= 1000
对于70%的数据, -100000 <= X, Y <= 100000
对于100%的数据, -1000000000 <= X, Y <= 1000000000
【输出格式】
输出dis(X, Y)
【样例输入】
0 1
【样例输出】
3

## 题目分析

### 模拟

模拟计算，只能通过78%的数据。

```c++
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int x,y,x2=0,y2=0;
	int dis[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
	long long ans=0,n=0,step=1;
	cin>>x>>y;
	while(x2!=x || y2!=y) {
		ans+=step;
		int d=(n++)%4; //前进方向 
		x2+=step*dis[d][0];
		y2+=step*dis[d][1];
		if(n%2==0) { //步长前进2次就+1 
			step++;
		}
		if(x2==x && y2!=y) { //x相同y不同 
			d=n%4;
            //y2向上走或向下走到y 
			if(dis[d][1]>0 && y-y2>0 && y-y2<=step || dis[d][1]<0 && y2-y>0 && y2-y<=step) {
				ans+=abs(y-y2);
				break;
			}
		}
		if(y2==y && x2!=x) {
			d=n%4;
			if(dis[d][0]>0 && x-x2>0 && x-x2<=step || dis[d][0]<0 && x2-x>0 && x2-x<=step) {
				ans+=abs(x-x2);
				break;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
```

### 找规律

![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2018072.png)
将螺旋折线改变一下，发现内部是正方形，正方形的边长构成等差数列8 16 24 ...
所以内圈的螺旋折线的长度可以通过等差数列求和求得。
最外圈的螺旋折线的长度该怎么计算呢？
![](https://cdn.jsdelivr.net/gh/love-ziji/LANQIAO/2018073.png)
我们用直线 y = x 将坐标轴平分，
y > x 时，内圈等差数列和加上最外圈的螺旋折线的长度 (x , y) - (-m, -m) = x + y + 2m > 0
y <= x 时，内圈加完整最外圈等差数列和减去最外圈多余的螺旋折线的长度 (x, y) - (-m, -m) = x + y + 2m >= 0
其中 m 为最外圈圈数，等于max(abs(x), abs(y))

```c++
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long x,y;
	cin>>x>>y;
	long long m=max(abs(x),abs(y)),ans;
	if(y > x) {
		ans=(4+4*(m-1))*(m-1)+x+y+2*m;
	}
	else {
		ans=(4+4*m)*m-x-y-2*m;
	}
	cout<<ans<<endl;
	
	return 0;
}
```