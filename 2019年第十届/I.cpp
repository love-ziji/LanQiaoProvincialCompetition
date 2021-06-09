#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,m,minNum=1e9,maxNum=-1e9,a[200001];
	long long sum=0;
	cin>>n>>m;
	for(int i=0;i<n+m+1;i++) {
		cin>>a[i];
		sum+=a[i];
		minNum=min(minNum,a[i]);
		maxNum=max(maxNum,a[i]);
	}
	if(m != 0) {
		if(minNum > 0) { //全是正数 
			sum-=2*minNum;
		} else {
			sum=0;
			for(int i=0;i<n+m+1;i++) { //有正有负 
				sum+=abs(a[i]);
			}
			if(maxNum < 0) { //全是负数 
				sum+=maxNum*2;
			}
		}
	}
	cout<<sum<<endl;
	
	return 0;
}
