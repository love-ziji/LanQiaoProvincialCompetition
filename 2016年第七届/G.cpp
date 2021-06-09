#include<iostream>
#include<cstring>
using namespace std;

int dis[4]={-1,1,-4,4},vis[13],num[5];
int n,sum=0;

void dfs(int a) {
	if(n == 5) {
		sum++;
		return;
	}
	for(int i=0;i<4;i++) {
		if(dis[i]==1 && (a==4 || a==8) || dis[i]==-1 && (a==5 || a==9)) {
			continue;
		}
		int t=a+dis[i];
		if(t>=1 && t<=12 && vis[t]==0 && (t==num[1] || t==num[2] || t==num[3] || t==num[4])) {
			vis[t]=1;
			n++;
			dfs(t);
		}
	}
}

int main()
{
	//12个数里选5个数出来的所有组合
	for(num[0]=1;num[0]<=12-4;num[0]++) {
		for(num[1]=num[0]+1;num[1]<=12-3;num[1]++) {
			for(num[2]=num[1]+1;num[2]<=12-2;num[2]++) {
				for(num[3]=num[2]+1;num[3]<=12-1;num[3]++) {
					for(num[4]=num[3]+1;num[4]<=12;num[4]++) {
						memset(vis,0,sizeof(vis));
						vis[num[0]]=1;
						n=1;
						dfs(num[0]);
					}
				}
			}
		}
	}
	cout<<sum<<endl;
	
	return 0;
}
