---
title: 蓝桥杯 2017年第八届省赛 C/C++ B组 07 日期问题
date: 2021-03-28 16:47:36
tags:
- STL
- 输入输出
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post4.jpg
---

## 题目描述

小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在 1960 年 1 月 1 日至 2059 年 12 月 31 日。令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。
比如02/03/04，可能是 2002 年 03 月 04 日、2004 年 02 月 03 日或 2004 年 03 月 02 日。
给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
输入
一个日期，格式是"AA/BB/CC"，(0 <= A, B, C <= 9)
输出
若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。
样例输入
02/03/04
样例输出
2002-03-04
2004-02-03
2004-03-02

## 题目分析

思维比较简单，直接判断三种可能的日期是否有意义。
输入输出比较考验技巧，难点在于排序和去重，去重容易忽略，不去重只能通过 78% 的数据。
先看一下我写的代码：

```c++
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
set<int> ans;

void f(int year,int month,int day) {
	if(month == 0 || month > 12) {
		return;
	}
	if(day == 0 || day > days[month]) {
		return;
	}
	if(year >= 60) {
		year+=1900;
	}
	else {
		year+=2000;
	}
	if(month == 2 && day == 29 && !(year%4==0&&year%100!=0 || year%400==0)) { //2月29日出现在非润年
		return;
	}
	ans.insert(year*10000+month*100+day);
}

int main()
{
	string dateStr;
	cin>>dateStr;
	int t=0,k=0,date[3];
	for(int i=0;i<=8;i++) {
		if(i%3 != 2) {
			t*=10;
			t+=dateStr[i]-48;
		}
		else {
			date[k++]=t;
			t=0;
		}
	}
	f(date[0],date[1],date[2]); //年月日
	f(date[2],date[0],date[1]); //月日年
	f(date[2],date[1],date[0]); //日月年
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++) {
		int day=*it%100;
		int month=*it/100%100;
		int year=*it/10000;
		cout<<year<<'-';
		if(month < 10) {
			cout<<'0'<<month<<'-';
		}
		else {
			cout<<month<<'-';
		}
		if(day < 10) {
			cout<<'0'<<day<<endl;
		}
		else {
			cout<<day<<endl;
		}
	}
	
	return 0;
}
```

再看一下我借鉴了其它题解之后写的代码：

```c++
#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct {
	int year,month,day;
} Date;

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int year(int y) {
	if(y >= 60) {
		y+=1900;
	}
	else {
		y+=2000;
	}
	return y;
}

bool compare(Date a,Date b) {
	if(a.year != b.year) {
		return a.year < b.year;
	}
	if(a.month != b.month) {
		return a.month < b.month;
	}
	return a.day < b.day;
}

int f(Date d) {
	if(d.year%4==0&&d.year%100!=0 || d.year%400==0) {
		days[2]=29;
	}
	else {
		days[2]=28;
	}
	if(d.month == 0 || d.month > 12) {
		return 0;
	}
	if(d.day == 0 || d.day > days[d.month]) {
		return 0;
	}
	return 1;
}

int main()
{
	int aa,bb,cc;
	scanf("%d/%d/%d",&aa,&bb,&cc); //巧用scanf
	int aa2=year(aa);
	int cc2=year(cc);
	Date date[3]={{aa2,bb,cc},{cc2,aa,bb},{cc2,bb,aa}};
	sort(date,date+3,compare);
	int i=0;
	while(i<3) {
		if(date[i].year==date[i+1].year && date[i].month==date[i+1].month && date[i].day==date[i+1].day) {
			date[i].year=0; //通过设置标志去重，先排序再去重
		}
		i++;
	}
	for(i=0;i<3;i++) {
		if(date[i].year && f(date[i])) {
			printf("%02d-%02d-%02d\n",date[i].year,date[i].month,date[i].day); //巧用printf 
		}
	}
	
	return 0;
}
```

大佬的输入输出真的受教了！我习惯了使用C++的输入输出，忘记了C语言输入输出的强大。使用结构体保存日期也是我没有想到的。