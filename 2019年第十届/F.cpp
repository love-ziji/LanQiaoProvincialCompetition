#include<iostream>
using namespace std;

int f(int n) {
	while(n) {
		if(n%10==2 || n%10==0 || n%10==1 || n%10==9) {
			return 1;
		}
		n/=10;
	}
	return 0;
}

int main()
{
	int n,res=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		if(f(i)) {
			res+=i;
		}
	}
	cout<<res<<endl;
	
	return 0;
}
