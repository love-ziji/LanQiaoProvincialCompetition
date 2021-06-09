#include<iostream>
using namespace std;

int n,m,k,sum=0,mapVal[50][50];

void dfs(int i,int j,int maxVal,int num) {
	if(i==n-1 && j==m-1) {
		if(num==k || maxVal<mapVal[i][j]&&num==k-1) { //走到出口时手中已有k件宝贝 或 手中有k-1件宝贝且出口格子中的宝贝价值比小明手中任意宝贝价值都大
			sum++;
			sum%=1000000007;
		}
	}
	if(i < n-1) { //能够向下走 
		if(maxVal < mapVal[i][j]) {
			dfs(i+1,j,mapVal[i][j],num+1); //拿起宝贝向下走 
		}
		dfs(i+1,j,maxVal,num); //不拿起宝贝向下走 
	}
	if(j < m-1) { //能够向右走 
		if(maxVal < mapVal[i][j]) {
			dfs(i,j+1,mapVal[i][j],num+1); //拿起宝贝向右走 
		}
		dfs(i,j+1,maxVal,num); //不拿起宝贝向右走 
	}
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>mapVal[i][j];
		}
	}
	dfs(0,0,-1,0);
	cout<<sum<<endl;
	
	return 0;
}
