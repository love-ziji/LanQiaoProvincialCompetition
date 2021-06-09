#include<iostream>
#include<vector>
using namespace std;

const int N=100001;

int vis[N]={0};
long long d[N],ans=-1e6;
vector<int> node[N-1]; //邻接矩阵

void dfs(int u) {
	vis[u]=1;
	for(int i=0;i<node[u].size();i++) {
		if(!vis[node[u][i]]) {
			dfs(node[u][i]);
			if(d[node[u][i]] > 0) {
				d[u]+=d[node[u][i]]; //状态转移方程 
			}
		}
	}
	ans=max(ans,d[u]);
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>d[i];
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
