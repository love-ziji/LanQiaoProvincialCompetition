#include<iostream>
using namespace std;

int main()
{
	int n,abc[3][100000];
	cin>>n;
	for(int i=0;i<3;i++) {
		for(int j=0;j<n;j++) {
			cin>>abc[i][j];
		}
	}
	long long ans=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(abc[0][i] < abc[1][j]) {
				for(int k=0;k<n;k++) {
					if(abc[1][j] < abc[2][k]) {
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
