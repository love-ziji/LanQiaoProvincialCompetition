#include<iostream>
using namespace std;

int isPrime(int n) {
	for(int i=2;i*i<=n;i++) {
		if(n%i == 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int prime[10001]={0,0};
	for(int i=2;i<=10000;i++) { //素数表
		prime[i]=isPrime(i);
	}
	for(int i=1;i<=1000;i++) { //循环公差
		for(int j=2;j<=1000;j++) { //循环首项
			if(prime[j] == 1) {
				int f=1;
				for(int k=1;k<=9;k++) {
					if(prime[j+k*i] == 0) {
						f=0;
						break;
					}
				}
				if(f == 1) {
					cout<<i<<endl;	
				}
			}
		}
	}
	
	return 0;
}
