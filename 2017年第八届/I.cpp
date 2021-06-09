#include<iostream>
using namespace std;
const int N=100000;

int main()
{
	int n,k,h,w,maxLen=0,num[N+1]={0};
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>h>>w;
		maxLen=max(maxLen,min(h,w));
		for(int j=1;j<=min(h,w);j++) {
			num[j]+=(h/j)*(w/j);
		}
	}
	for(int i=maxLen;i>0;i--) {
		if(num[i] >= k) {
			cout<<i<<endl;
			break;
		}
	}
	
	return 0;
}
