#include<iostream>
#include<vector>
using namespace std;

const int N=100001;

int val[N],vis[N]={0};
long long dp[N][2],ans=-1e6;
vector<int> node[N-1]; //ÁÚ½Ó¾ØÕó

void dfs(int u) {
	dp[u][0]=0;
	dp[u][1]=val[u];
	vis[u]=1;
	for(int i=0;i<node[u].size();i++) {
		if(!vis[node[u][i]]) {
			dfs(node[u][i]);
			dp[u][1]+=max(dp[node[u][i]][1],dp[node[u][i]][0]);
		}
	}
	ans=max(ans,max(dp[u][1],dp[u][0]));
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>val[i];
	}
	int u,v;
	for(int i=0;i<n-1;i++) {
		cin>>u>>v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	dfs(u);
	cout<<ans<<endl;
	
	return 0;
}
