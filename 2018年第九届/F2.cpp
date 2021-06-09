#include<iostream>
using namespace std;

int main()
{
	int n,t,abc[3][100001]={0},maxabc[3]={0};
	cin>>n;
	for(int i=0;i<3;i++) {
		for(int j=0;j<n;j++) {
			cin>>t;
			abc[i][t]++; //分别保存三个数组中每个整数出现的次数
			if(t > maxabc[i]) {
				maxabc[i]=t;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=maxabc[0];i++) {
		if(abc[0][i]) {
			for(int j=i+1;j<=maxabc[1];j++) {
				if(abc[1][j]) {
					for(int k=j+1;k<=maxabc[2];k++) {
						if(abc[2][k]) {
							ans+=abc[0][i]*abc[1][j]*abc[2][k];
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
