#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,a[50];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int sumL=0,sumR=0;
	for(int i=1;i<n;i++) {
		if(abs(a[0])>abs(a[i]) && a[i]>0) {
			sumL++; //所有左边右行蚂蚁的数量
		}
		if(abs(a[0])<abs(a[i]) && a[i]<0) {
			sumR++; //所有右边左行蚂蚁的数量
		}
	}
	if(a[0]>0 && sumR>0 || a[0]<0 && sumL>0) { //存在第一次相遇
		cout<<1+sumL+sumR<<endl;
	} else {
		cout<<1<<endl;
	}
	
	return 0;
}
