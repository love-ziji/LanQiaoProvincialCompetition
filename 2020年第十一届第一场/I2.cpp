#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100000;

int n,k;
int a[N];
int cnt[11][N];
long long ans=0;

int digits(int n) {
	int num=0;
	while(n) {
		num++;
		n/=10;
	}
	return num;
}

void f() {
	for(int i=0;i<n;i++) {
		ans+=cnt[digits(a[i])][(k-a[i]%k)%k];
		for(int j=1,p=10%k;j<=10;j++) {
			cnt[j][a[i]%k*1LL*p%k]++;
			p=p*10%k;
		}
	}
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	f(); //AiAj,i<j
	reverse(a,a+n); //反转数组
	memset(cnt,0,sizeof(cnt));
	f(); //AiAj,i>j
	cout<<ans<<endl;
	
	return 0;
}
