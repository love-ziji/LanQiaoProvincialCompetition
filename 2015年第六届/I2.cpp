#include<iostream>
using namespace std;

typedef long long int ll;
typedef struct {
	ll m[7][7];
} Mat;

const int MOD=1e9+7;

// æÿ’Û≥À∑® 
Mat mul(Mat a,Mat b) {
	Mat c;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			c.m[i][j]=0;
			for(int k=1;k<=6;k++) {
				c.m[i][j]+=a.m[i][k]*b.m[k][j]%MOD;
				c.m[i][j]%=MOD;
			}
		}
	}
	return c;
}

// æÿ’ÛøÏÀŸ√› 
Mat pow(Mat a,int n) {
	Mat r;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			r.m[i][j]=i==j ? 1 : 0;
		}
	}
	while(n) {
		if(n&1) {
			r=mul(a,r);
		}
		a=mul(a,a);
		n>>=1;
	}
	return r;
}

// øÏÀŸ√› 
ll pow(ll a,int n) {
	ll r=1;
	while(n) {
		if(n&1) {
			r=r*a%MOD;
		}
		a=a*a%MOD;
		n>>=1;
	}
	return r;
}

int main()
{
	int n,m;
	cin>>n>>m;
	Mat dp;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			dp.m[i][j]=1;
		}
	}
	int a,b;
	for(int i=0;i<m;i++) { //ππ‘Ï◊™“∆æÿ’Û£®º¥≥ÂÕªæÿ’Û£©
		cin>>a>>b;
		dp.m[a][(b+3)%6==0 ? 6 : (b+3)%6]=0;
		dp.m[b][(a+3)%6==0 ? 6 : (a+3)%6]=0;
	}
	dp=pow(dp,n-1);
	ll sum=0;
	for(int i=1;i<=6;i++) {
		for(int j=1;j<=6;j++) {
			sum+=dp.m[i][j];
			sum%=MOD;
		}
	}
	cout<<sum*pow(4,n)%MOD<<endl;
	
	return 0;
}
