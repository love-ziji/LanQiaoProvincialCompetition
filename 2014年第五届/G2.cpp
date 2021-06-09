#include<iostream>
using namespace std;

int res[9]={0};
int a[9]={2,4,5,6,7,9,10,11,12};
int vis[9]={0};

void dfs(int n) {
	if(n == 9) {
		int sum1=1+res[0]+res[3]+res[5];
		int sum2=1+res[1]+res[4]+res[8];
		int sum3=res[5]+res[6]+res[7]+res[8];
		int sum4=3+res[6]+res[3]+8;
		int sum5=3+res[7]+res[4]+res[2];
		int sum6=8+res[0]+res[1]+res[2];
		if(sum1==26 && sum2==26 && sum3==26 && sum4==26 && sum5==26 && sum6==26) {
			cout<<res[3]<<endl;
		}
		return;
	}
	for(int i=0;i<9;i++) {
		if(vis[i] == 1) {
			continue;
		}
		vis[i]=1;
		res[n]=a[i];
		dfs(n+1);
		vis[i]=0;
	}
}

int main()
{
	dfs(0);
	
	return 0;
}
