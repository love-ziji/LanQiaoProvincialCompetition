#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=300001;

int n;
long long s[N],a[N];
int vis[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) {
		s[0]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%lld",&s[i]);
			s[i]+=s[i-1]; //计算前缀和 
		}
		long long s0=s[0],sn=s[n];
		if(s0>sn) {
			swap(s0,sn);
		}
		sort(s,s+n+1);
		for(int i=0;i<=n;i++) { //寻找最小值下标 
			if(s[i]==s0) {
				s0=i;
				break;
			}
		}
		for(int i=n;i>=0;i--) { //寻找最大值下标 
			if(s[i]==sn) {
				sn=i;
				break;
			}
		}
		int p=0,q=n;
		memset(vis,0,sizeof(vis));
		// 取数 
		for(int i=s0;i>=0;i-=2) {
			a[p++]=s[i];
			vis[i]=1;
		}
		for(int i=sn;i<=n;i+=2) {
			a[q--]=s[i];
			vis[i]=1;
		}
		for(int i=0;i<=n;i++) {
			if(!vis[i]) {
				a[p++]=s[i];
			}
		}
		long long res=0;
		for(int i=1;i<=n;i++) {
			res=max(res,abs(a[i]-a[i-1]));
		}
		printf("%lld\n",res);
	}
	
	return 0;
}
