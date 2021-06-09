#include<iostream>
using namespace std;

int res=0,a[13]={0};

void fun(int n) {
	if(n == 13) {
		int sum=0;
		for(int i=0;i<13;i++) {
			sum+=a[i];
		}
		if(sum == 13) {
			res++;
		}
		return;
	}
	for(int i=0;i<=4;i++) {
		a[n]=i;
		fun(n+1);
	}
} 

int main()
{
	fun(0);
	cout<<res<<endl;
	
	return 0;	
} 
