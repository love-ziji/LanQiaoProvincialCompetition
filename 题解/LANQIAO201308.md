---
title: 蓝桥杯 2013年第四届省赛 C/C++ B组 08 翻硬币
date: 2021-03-13 15:52:41
tags:
- 找规律
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post1.jpg
---

## 题目描述

小明正在玩一个“翻硬币”的游戏。
桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。
比如，可能情形是：\*\*oo\*\*\*oooo
如果同时翻转左边的两个硬币，则变为：oooo\*\*\*oooo
现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？
我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求： 
程序输入：
两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度 < 1000
程序输出：
一个整数，表示最小操作步数
例如：
用户输入：
\*\*\*\*\*\*\*\*\*\*
o\*\*\*\*o\*\*\*\*
程序应该输出：
5
再例如：
用户输入：
\*o\*\*o\*\*\*o\*\*\*
\*o\*\*\*o\*\*o\*\*\*
程序应该输出：
1

## 题目分析

### 解法一

我们发现若初始状态与目标状态的第 i 个硬币正反面不同，则必然有另外一个第 j 个硬币正反面也不同（正反面不同的硬币个数必然是偶数，否则初始状态无法通过每次只能同时翻转相邻两个硬币的操作达到目标状态），且翻动 j - i 次，初始状态与目标状态的第 i 个硬币至第 j 个硬币正反面相同。

```c++
#include<iostream>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int n=-1,sum=0; //n不能取0 
    for(int i=0;i<str1.size();i++) {
        if(str1[i] != str2[i]) {
            if(n != -1) {
                sum+=i-n;
                n=-1;
            } else {
                n=i;
            }
        }
    }
    cout<<sum<<endl;
    
    return 0;
}
```

### 解法二

循环比较初始状态与目标状态每个硬币的正反面是否相同，若第 i 个硬币正反面不同，则进行翻转操作，翻转初始状态的第 i 个硬币和第 i+1 个硬币，翻转后初始状态与目标状态的第 i 个硬币正反面必然相同，所以可以只翻转初始状态的第 i+1 个硬币，翻转后继续比较第 i+1 个硬币。

```c++
#include<iostream>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int sum=0;
    for(int i=0;i<str2.size();i++) {
        if(str1[i] != str2[i]) {
            if(str1[i+1] == '*') {
            	str1[i+1]='o';
            } else {
                str1[i+1]='*';
            }
            sum++;
        }
    }
    cout<<sum<<endl;
    
    return 0;
}
```