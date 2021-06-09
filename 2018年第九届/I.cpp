#include<iostream>
using namespace std;
const int N=1000;

int n;
char map[N][N];
int vis[N][N]={0};
int f[N*N]={0};

void dfs(int x,int y,int num) {
	if(x<0 || y<0 || x>=n || y>=n) {
		return;
	}
	if(map[x][y] == '.') {
		return;
	}
	if(vis[x][y]) {
		return;
	}
	vis[x][y]=1;
	if(map[x-1][y]=='#' && map[x+1][y]=='#' && map[x][y+1]=='#' && map[x][y-1]=='#') {
		f[num]++;
	}
	dfs(x-1,y,num);
	dfs(x+1,y,num);
	dfs(x,y+1,num);
	dfs(x,y-1,num);
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>map[i][j];
		}
	}
	int num=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(map[i][j]=='#' && !vis[i][j]) {
				dfs(i,j,num);
				num++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<num;i++) {
		if(f[i] == 0) {
			ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
