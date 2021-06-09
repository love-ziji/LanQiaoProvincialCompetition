#include<iostream>
using namespace std;

int main()
{
	int phone=3,floor=1000,dp[4][1001];
	for(int i=1;i<=phone;i++) {
		for(int j=1;j<=floor;j++) {
			dp[i][j]=j; //初始化为最坏情况 
		}
	}
	for(int i=2;i<=phone;i++) {
		for(int j=1;j<=floor;j++) {
			for(int k=1;k<j;k++) {
				dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1); //状态转移方程 
			}
		}
	}
	cout<<dp[3][1000]<<endl;
	
	return 0;
}
