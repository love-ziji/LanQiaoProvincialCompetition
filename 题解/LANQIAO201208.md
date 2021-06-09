---
title: 蓝桥杯 2012年第三届省赛 C/C++ B组 08 密码发生器
date: 2021-03-10 11:57:47
tags:
- 字符串
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post4.jpg
---

## 题目描述

在对银行账户等重要权限设置密码的时候，我们常常遇到这样的烦恼：如果为了好记用生日吧，容易被破解，不安全；如果设置不好记的密码，又担心自己也会忘记；如果写在纸上，担心纸张被别人发现或弄丢了...
这个程序的任务就是把一串拼音字母转换为 6 位数字（密码）。我们可以使用任何好记的拼音串(比如名字，王喜明，就写：wangximing)作为输入，程序输出 6 位数字。
变换的过程如下：
第一步. 把字符串 6 个一组折叠起来，比如 wangximing 则变为：
wangxi
ming 
第二步. 把所有垂直在同一个位置的字符的 ascii 码值相加，得出 6 个数字，如上面的例子，则得出：
228 202 220 206 120 105
第三步. 再把每个数字“缩位”处理：就是把每个位的数字相加，得出的数字如果不是一位数字，就再缩位，直到变成一位数字为止。例如: 
228 => 2+2+8=12 => 1+2=3
上面的数字缩位后变为：344836，这就是程序最终的输出结果！
要求程序从标准输入接收数据，在标准输出上输出结果。
输入格式为：第一行是一个整数n（<100），表示下边有多少输入行，接下来是 n 行字符串，就是等待变换的字符串。
输出格式为：n 行变换后的 6 位密码。
例如，输入：
5
zhangfeng
wangximing
jiujingfazi
woaibeijingtiananmen
haohaoxuexi
则输出：
772243
344836
297332
716652
875843

## 题目分析

注意以字符为单位处理字符串的方法，使用 str.size() 函数。

```c++
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[6]={0};
	string str;
	for(int i=0;i<n;i++) {
		cin>>str;
		//以字符为单位处理字符串
		for(int j=0;j<str.size();j++) {
			a[j%6]+=str[j];
		}
		for(int j=0;j<6;j++) {
			while(a[j]/10) {
				int sum=0;
				while(a[j]) {
					sum+=a[j]%10;
					a[j]/=10;
				}
				a[j]=sum;
			}
			cout<<a[j];
			a[j]=0;
		}
	}
	
	return 0;
}
```
