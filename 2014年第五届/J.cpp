#include<iostream>
using namespace std;

int main()
{
	int n,h[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>h[i];
	}
	int numR,numL;
	long long sum=0;
	for(int i=0;i<n;i++) {
		numR=numL=0;
		for(int j=i+1;j<n;j++) {
			if(h[j] < h[i]) {
				numR++; //右边比起小 
			}
		}
		for(int j=i-1;j>=0;j--) {
			if(h[j] > h[i]) {
				numL++; //左边比起大 
			}
		}
		sum+=(1+numR+numL)*(numR+numL)/2;
	}
	cout<<sum<<endl;
	
	return 0;
}
