#include<iostream>
using namespace std;

int gcd(int a,int b) {
	return b==0 ? a : gcd(b,a%b);
}

int main()
{
	int n,d=0,a[100],dp[10001]={0};
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		d=gcd(d,a[i]);
	}
	if(d != 1) {
		cout<<"INF"<<endl;
		return 0;
	} 
	for(int i=0;i<n;i++) {
		dp[a[i]]=1;
		for(int j=1;j+a[i]<=10000;j++) {
			if(dp[j]) {
				dp[j+a[i]]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=10000;i++) {
		if(!dp[i]) {
			ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
