#include<iostream>
using namespace std;
const int N=100000;

int main()
{
	int n,k,a[N+1];
	long long s[N+1]={0};
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	long long ans=0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<=n;j++) {
			if((s[j]-s[i])%k == 0) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
