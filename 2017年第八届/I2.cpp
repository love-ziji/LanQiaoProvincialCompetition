#include<iostream>
using namespace std;

const int N=100000;
int n,k,h[N],w[N],maxLen=0;

bool f(int len) {
	int num=0;
	for(int i=0;i<n;i++) {
		num+=(h[i]/len)*(w[i]/len);
	}
	return num>=k;
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>h[i]>>w[i];
		maxLen=max(maxLen,min(h[i],w[i]));
	}
	int L=1,R=maxLen,Mid;
	while(L<=R) {
		Mid=(L+R)/2;
		f(Mid) ? L=Mid+1 : R=Mid-1;
	}
	cout<<L-1<<endl;
	
	return 0;
}
