#include<iostream>
#include<cstring>
using namespace std;
const int MOD=10000;

void mul(int a[3][3],int b[3][3]) {
	int t[3][3]={0};
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			for(int k=0;k<3;k++) {
				t[i][j]=(t[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
			}
		}
	}
	memcpy(a,t,sizeof(t));
}

int main()
{
	int t[3][3]={{0,1,0},{0,0,1},{1,1,1}},res[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	int n=20190324-3;
	while(n) {
		if(n&1) {
			mul(res,t);
		}
		mul(t,t);
		n>>=1;
	}
	cout<<(res[2][0]+res[2][1]+res[2][2])%MOD<<endl;
	
	return 0;
}
