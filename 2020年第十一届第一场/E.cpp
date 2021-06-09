#include<iostream>
using namespace std;

int dp[1011][1011]; //dp[i][j]：第一行有i个数，第二行有j个数的方案数

int main()
{
	for(int i=0;i<=1010;i++) {
		for(int j=0;j<=i;j++) { //j<=i保证同一列中下边的比上边的大（按从小到大的顺序填数）
			if(i>=1 && j>=1) {
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			} else if(i>=1) {
				dp[i][j]=dp[i-1][j];
			} else if(j>=1) {
				dp[i][j]=dp[i][j-1];
			} else {
				dp[i][j]=1; //初始化
			}
			dp[i][j]%=2020;
		}
	}
	cout<<dp[1010][1010]<<endl;
	 
	return 0;
}
