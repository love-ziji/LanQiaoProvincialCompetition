---
title: 蓝桥杯 2019年第十届省赛 C/C++ B组 H 等差数列
date: 2021-04-12 16:57:27
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post8.jpg
---

## 题目描述

数学老师给小明出了一道等差数列求和的题目。但是粗心的小明忘记了一部分的数列，只记得其中 N 个整数。
现在给出这 N 个整数，小明想知道包含这 N 个整数的最短的等差数列有几项？
【输入格式】
输入的第一行包含一个整数 N。
第二行包含 N 个整数 A1, A2, · · · , AN。(注意 A1 ∼ AN 并不一定是按等差数列中的顺序给出)
【输出格式】
输出一个整数表示答案。
【样例输入】
5
2 6 4 10 20
【样例输出】
10
【样例说明】
包含 2、6、4、10、20 的最短的等差数列是 2、4、6、8、10、12、14、16、18、20。
【评测用例规模与约定】
对于所有评测用例，2 ≤ N ≤ 100000，0 ≤ Ai ≤ 10^9。

## 题目分析

从小到大排序后计算相邻两项的差值，最小差值即为公差。
注意公差为 0 应单独讨论。

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,a[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	int minDiff=a[1]-a[0];
	for(int i=2;i<n;i++) {
		int diff=a[i]-a[i-1];
		if(diff<minDiff) {
			minDiff=diff;
		}
	}
	if(minDiff==0) { //d=0 
		cout<<n<<endl;
	} else {
		cout<<(a[n-1]-a[0])/minDiff+1<<endl;
	}
	
	return 0;
}
```