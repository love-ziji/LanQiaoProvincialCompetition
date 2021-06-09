#include<iostream>
using namespace std;

int main()
{
	int dp[14][14]={0}; //dp[i][j]：选完i点数的牌，剩余j张牌待选时的组合数
	for(int i=9;i<=13;i++) {
		dp[1][i]=1;
	}
	for(int i=2;i<=13;i++) {
		for(int j=0;j<=13;j++) {
			//状态转移方程 
			for(int k=0;k<=4&&j+k<=13;k++) {
				dp[i][j]+=dp[i-1][j+k];
			}
		}
	}
	cout<<dp[13][0]<<endl;
	
	return 0;
}
