#include<iostream>
using namespace std;

int main()
{
	int n,m,dp[31][31]; //dp[i][j]：走到第i行第j列的方案数
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(i%2==0 && j%2==0) {
				dp[i][j]=0;
				continue;
			}
			if(i==1 && j==1) {
				dp[i][j]=1;
			} else if(i==1) {
				dp[i][j]=dp[i][j-1];
			} else if(j==1) {
				dp[i][j]=dp[i-1][j];
			} else {
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	cout<<dp[n][m]<<endl;
	
	return 0;
}
