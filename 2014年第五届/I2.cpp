#include<iostream>
#include<cstring>
using namespace std;

int n,m,k,mapVal[50][50],dp[50][50][13][13]; 

int dfs(int i,int j,int maxVal,int num) {
	if(dp[i][j][maxVal+1][num] != -1) { //若不等于-1，则表示已搜索过
		return dp[i][j][maxVal+1][num];
	}
	if(i==n-1 && j==m-1) {
		if(num==k || maxVal<mapVal[i][j]&&num==k-1) {
			return dp[i][j][maxVal+1][num]=1;
		} else {
			return dp[i][j][maxVal+1][num]=0;
		}
	}
	long long sum=0;
	if(i < n-1) {
		if(maxVal < mapVal[i][j]) {
			sum+=dfs(i+1,j,mapVal[i][j],num+1);
		}
		sum+=dfs(i+1,j,maxVal,num);
	}
	if(j < m-1) {
		if(maxVal < mapVal[i][j]) {
			sum+=dfs(i,j+1,mapVal[i][j],num+1);
		}
		sum+=dfs(i,j+1,maxVal,num);
	}
	//宝贝价值可能为0，所以手中已有宝贝的最大价值初始值为-1
	//数组下标最小值为0，所以是maxVal+1
	return dp[i][j][maxVal+1][num]=sum%1000000007;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>mapVal[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,0,-1,0)<<endl;
	
	return 0;
}
