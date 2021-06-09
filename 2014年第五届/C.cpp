#include<iostream>
using namespace std;

int sum=0;

void dfs(int liquor,int shop,int flower) {
	if(shop>5 || flower>10) {
		return;
	}
	if(liquor==1 && shop==5 && flower==9) {
		sum++;
		return;
	}
	dfs(liquor*2,shop+1,flower);
	dfs(liquor-1,shop,flower+1);
}

int main()
{
	dfs(2,0,0);
	cout<<sum<<endl;
	
	return 0;
}
