#include<iostream>
using namespace std;

int n,m;
int ans=0;

void dfs(int x,int y) {
	if(x>n || y>m) {
		return;
	}
	if(x%2==0 && y%2==0) {
		return;
	}
	if(x==n && y==m) {
		ans++;
	}
	dfs(x+1,y);
	dfs(x,y+1);
}

int main()
{
	cin>>n>>m;
	dfs(1,1);
	cout<<ans<<endl;
	
	return 0;
}
