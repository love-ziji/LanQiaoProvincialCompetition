#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long n=1,a[30][30]={0};
	for(int i=0;i<29;i++) {
		n<<=1;
	}
	for(int i=0;i<29;i++) {
		for(int j=0;j<=i;j++) {
			cin>>a[i][j];
			a[i][j]*=n;
		}
	}
	for(int i=0;i<29;i++) {
		for(int j=0;j<=i;j++) {
			long long t=a[i][j]/2;
			a[i+1][j]+=t;
			a[i+1][j+1]+=t;
		}
	}
	sort(a[29],a[29]+30);
//	cout<<a[29][0]<<endl;
	cout<<a[29][29]<<endl;
	
	return 0;
}
