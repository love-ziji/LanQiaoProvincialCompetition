---
title: 蓝桥杯 2012年第三届省赛 C/C++ B组 02 古堡算式
date: 2021-03-09 21:01:36
tags:
- 全排列
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post1.jpg
---

## 题目描述

福尔摩斯到某古堡探险，看到门上写着一个奇怪的算式：
ABCDE * ? = EDCBA
他对华生说：“ABCDE 应该代表不同的数字，问号也代表某个数字！”
华生：“我猜也是！”
于是，两人沉默了好久，还是没有算出合适的结果来。
请你利用计算机的优势，找到破解的答案。
把 ABCDE 所代表的数字写出来。

## 题目分析

全排列问题，暴力枚举或使用 next_permutation() 函数。

### 暴力枚举

```c++
#include<iostream>
using namespace std;

int main()
{
	for(int a=1;a<10;a++) { //A和E为首位不能为零
		for(int b=0;b<10;b++) {
			for(int c=0;c<10;c++) {
				for(int d=0;d<10;d++) {
					for(int e=1;e<10;e++) {
						//两两互不相同
						if(a!=b && a!=c && a!=d && a!=e && b!=c && b!=d && b!=e && c!=d && c!=e && d!=e) {
							for(int t=0;t<10;t++) {
								int left=a*10000+b*1000+c*100+d*10+e;
								int right=e*10000+d*1000+c*100+b*10+a;
								if(left*t == right) {
									cout<<left<<endl;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
 }
```

### next_permutation()函数

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int numArr[10] ={0,1,2,3,4,5,6,7,8,9};
	do {
		if(numArr[0]!=0 && numArr[4]!=0) {
			int left=numArr[0]*10000+numArr[1]*1000+numArr[2]*100+numArr[3]*10+numArr[4];
			int right=numArr[4]*10000+numArr[3]*1000+numArr[2]*100+numArr[1]*10+numArr[0];
			for(int t=0;t<10;t++) {
				if(left*t == right) {
					cout<<left<<endl;
					return 0;
				}
			}
		}
	} 
	while(next_permutation(numArr,numArr+10)); //全排列函数next_permutation()
	
	return 0;
}
```

## 题目答案

**21978**