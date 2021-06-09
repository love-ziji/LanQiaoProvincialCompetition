#include<iostream>
using namespace std;

int main()
{
	int n,a[10001];
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<n;i++) {
		if(a[i] != i) {
			for(int j=i+1;j<=n;j++) {
				if(a[j] == i) {
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
					sum++;
					break;
				}
			}
		}
	}
	cout<<sum<<endl;
	
	return 0;
}
