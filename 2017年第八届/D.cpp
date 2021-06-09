#include<iostream>
using namespace std;

int vis[7][7]={0};
int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans=0;

void dfs(int x,int y) {
	if(x==0 || y==0 || x==6 || y==6) {
		ans++;
		return;
	}
	for(int i=0;i<4;i++) {
		int tx=x+dis[i][0];
		int ty=y+dis[i][1];
		if(!vis[tx][ty]) {
			vis[tx][ty]=1;
			vis[6-tx][6-ty]=1;
			dfs(tx,ty);
			vis[tx][ty]=0;
			vis[6-tx][6-ty]=0;
		}
	}
}

int main()
{
	vis[3][3]=1;
	dfs(3,3);
	cout<<ans/4<<endl;
	
	return 0;
}
