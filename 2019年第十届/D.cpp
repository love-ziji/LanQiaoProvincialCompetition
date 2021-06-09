#include<iostream>
using namespace std;

int f(int n) {
	while(n) {
		if(n%10==2 || n%10==4) {
			return 0;
		}
		n/=10;
	}
	return 1;
}

int main()
{
	int res=0;
	for(int i=1;i<=2019-2;i++) {
		if(f(i)) {
			for(int j=i+1;j<2019-i-j;j++) {
				if(f(j) && f(2019-i-j)) {
					res++;
				}
			}
		}
	}
	cout<<res<<endl;
	
	return 0;
}
