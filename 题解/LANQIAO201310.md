---
title: 蓝桥杯 2013年第四届省赛 C/C++ B组 10 连号区间数
date: 2021-03-13 16:45:37
tags:
- 找规律
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post3.jpg
---

## 题目描述

小明这些天一直在思考这样一个奇怪而有趣的问题：
在 1 ~ N 的某个全排列中有多少个连号区间呢？这里所说的连号区间的定义是：
如果区间 [L, R] 里的所有元素（即此排列的第L个到第R个元素）递增排序后能得到一个长度为 R - L + 1 的“连续”数列，则称这个区间为连号区间。
当 N 很小的时候，小明可以很快地算出答案，但是当 N 变大的时候，问题就不是那么简单了，现在小明需要你的帮助。
输入格式：
第一行是一个正整数 N  (1 <= N <= 50000)，表示全排列的规模。
第二行是 N 个不同的数字 Pi (1 <= Pi <= N)，表示这 N 个数字的某一全排列。
输出格式：
输出一个整数，表示不同连号区间的数目。
示例：
用户输入：
4
3 2 4 1
程序应输出：
7
用户输入：
5
3 4 2 5 1
程序应输出：
9
解释：
第一个用例中，有 7 个连号区间分别是：[1,1], [1,2], [1,3], [1,4], [2,2], [3,3], [4,4]
第二个用例中，有 9 个连号区间分别是：[1,1], [1,2], [1,3], [1,4], [1,5], [2,2], [3,3], [4,4], [5,5]

## 题目分析

直接将区间 [L, R] 里的元素排序后判断是否“连续”，只能通过 67% 的数据。
我们发现若R - L == maxNum - minNum（maxNum、minNum分别为区间 [L, R] 里的最大元素和最小元素），则区间 [L, R] 为连号区间，且若L = R，则区间 [L, R] 为连号区间。

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,maxNum,minNum,sum=0,arr[50000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++) {
		maxNum=arr[i];
		minNum=arr[i];
		for(int j=i+1;j<n;j++) {
			if(arr[j] > maxNum) {
				maxNum=arr[j];
			}
			if(arr[j] < minNum) {
				minNum=arr[j];
			}
			if(maxNum-minNum == j-i) { 
				sum++;
			}
		}
	}
	cout<<sum+n<<endl; //若L=R，则区间[L, R]为连号区间 
	
	return 0;
}
```

