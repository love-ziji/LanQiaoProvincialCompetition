---
title: 蓝桥杯 2019年第十届省赛 C/C++ B组 B 年号字串
date: 2021-04-11 21:08:18
tags:
- STL
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post3.jpg
---

## 题目描述

小明用字母 A 对应数字 1，B 对应 2，以此类推，用 Z 对应 26。对于 27 以上的数字，小明用两位或更长位的字符串来对应，例如 AA 对应 27，AB 对应 28，AZ 对应 52，LQ 对应 329。
请问 2019 对应的字符串是什么？

## 题目分析

这道题其实笔算更快，但因为进制转换比较常用，所以还是码了代码，使用栈 stack 先进后出的性质即可较容易的实现进制转换。

```c++
#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<char> s;
	int n;
	cin>>n;
	while(n) {
		s.push('A'+n%26-1);
		n/=26;
	}
	while(!s.empty()) {
		cout<<s.top();
		s.pop();
	}
	
	return 0;
}
```

### 题目答案

**BYQ**