#include<iostream>
using namespace std;

int a[11]={0};

int dfs(int n,int score) {
	if(n > 11) {
		return 0;
	}
	if(n==11 && score==100) {
		for(int i=1;i<=10;i++) {
			cout<<a[i];
		}
		cout<<endl;
		return 0;
	}
	a[n]=0;
	dfs(n+1,score-n);
	a[n]=1;
	dfs(n+1,score*2);
}

int main()
{
	dfs(1,10);
	return 0;
}
