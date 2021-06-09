#include<iostream>
#include<cmath>
using namespace std;

int digits(int n) {
	int num=0;
	while(n) {
		num++;
		n/=10;
	}
	return num;
}

int main()
{
	int n,k,a[100000],digit[100000];
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		digit[i]=digits(a[i]);
	}
	long long ans=0;
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(a[i]%k==0 && a[j]%k==0) {
				ans+=2;
				continue;
			}
			long long num1=a[i]*1LL*pow(10,digit[j])+a[j];
			long long num2=a[j]*1LL*pow(10,digit[i])+a[i];
			if(num1%k==0) {
				ans++;
			}
			if(num2%k==0) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
