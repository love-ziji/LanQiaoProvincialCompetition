#include<iostream>
using namespace std;
const int N=100000;

int main()
{
	int n,k,a[N+1];
	long long s[N+1]={0},num[N]={0};
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		num[s[i]%k]++;
	}
	long long ans=num[0];
	for(int i=0;i<k;i++) {
		if(num[i] > 1) {
			ans+=num[i]*(num[i]-1)/2;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
