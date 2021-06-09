---
title: 蓝桥杯 2013年第四届省赛 C/C++ B组 04 黄金连分数
date: 2021-03-12 21:24:55
tags:
- 大数处理
- 斐波那契数列
categories:
- 蓝桥杯
cover: https://cdn.jsdelivr.net/gh/love-ziji/CDN/post4.jpg
---

## 题目描述

黄金分割数0.61803... 是个无理数，这个常数十分重要，在许多工程问题中会出现。有时需要把这个数字求得很精确。
对于某些精密工程，常数的精度很重要。也许你听说过哈勃太空望远镜，它首次升空后就发现了一处人工加工错误，对那样一个庞然大物，其实只是镜面加工时有比头发丝还细许多倍的一处错误而已，却使它成了“近视眼”！
言归正传，我们如何求得黄金分割数的尽可能精确的值呢？有许多方法。
比较简单的一种是用连分数：

                     1
    黄金数 = --------------------
                        1
              1 + --------------
                         1
                1 + ------------
                          1
                  1 + ----------
                       1 + ...

这个连分数计算的“层数”越多，它的值越接近黄金分割数。
请你利用这一特性，求出黄金分割数的足够精确值，要求四舍五入到小数点后 100 位。
小数点后3位的值为：0.618
小数点后4位的值为：0.6180
小数点后5位的值为：0.61803
小数点后7位的值为：0.6180340
（注意尾部的0，不能忽略）

## 题目分析

我们发现1/2 2/3 3/5 5/8...为斐波那契数列前一项除以后一项，相除模拟手算除法，先整除，然后用余数乘以 10 继续整除。
但由于 C/C++ 整型数据的限制（unsigned long long 取值范围为[0,2^64-1]），无法精确到小数点后 100 位，除非自己创建大数类。

```c++
#include<iostream>
using namespace std;

int main()
{
	unsigned long long a[100]={0,1};
	for(int i=2;i<100;i++) {
		a[i]=a[i-1]+a[i-2];
		cout<<i<<' '<<a[i]<<endl; //a[94]越界
	}
	unsigned long long x=a[88],y=a[89];
	// 模拟手算除法：先整除，然后用余数乘以10继续整除
	for(int i=1;i<=102;i++) {
		cout<<x/y;
		x=(x%y)*10; //乘10可能导致越界，测试得x=a[88],y=a[89]，但只能精确到小数点后36位
	}
	
	return 0;
}
```

大数处理推荐使用 Java 的 BigInteger 类，填空题可以使用Java、Python，哪种语言解决这道题简单用哪种！

```java
package lanqiao2013;

import java.math.BigInteger;

/*
BigInteger类相关运算
a+b:a.add(b)
a-b:a.subtract(b)
a*b:a.multiply(b)
a/b:a.divide(b)
a%b:a.mod(b)
a==b:a.compareTo(b)==0
*/

public class D {

    public static void main(String[] args) {
        BigInteger a, b;
        BigInteger arr1[] = new BigInteger[102];
        BigInteger arr2[] = new BigInteger[102];

        int f = 1, f2; //f标志是否为第一次循环，f2标志是否精确到了小数点后100位
        for (int end = 100; end < 200; end++) { //end为斐波拉契数列循环次数
            a = BigInteger.ZERO;
            b = BigInteger.ONE;

            // 计算斐波拉契数列
            for (int i = 1; i < end; i++) {
                a = a.add(b);
                b = b.add(a);
            }

            // 模拟手算除法：先整除，然后用余数乘以10继续整除
            for (int i = 0; i < 102; i++) {
                if (f == 1) {
                    arr1[i] = a.divide(b);
                } else {
                    arr2[i] = a.divide(b);
                }
                a = a.mod(b).multiply(BigInteger.TEN);
            }

            if (f == 0) {
                f2 = 1;
                for (int i = 0; i < 102; i++) { //判断是否精确到了小数点后100位
                    System.out.print(arr1[i]);
                    if (arr1[i].compareTo(arr2[i]) != 0) {
                        arr1[i] = arr2[i];
                        f2 = 0;
                    }
                }
                System.out.println();
                if (f2 == 1) {
                    break;
                }
            }
            f = 0;
        }
    }
}
```

## 题目答案

**0.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911375**