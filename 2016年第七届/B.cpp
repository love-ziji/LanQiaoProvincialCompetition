#include<iostream>
using namespace std;

int main()
{
	for(int i=1;i<=99;i++) {
		for(int j=i+1;j<=100;j++) {
			int sum=(i+j)*(j-i+1)/2;
			if(sum == 236) {
				cout<<i<<endl;
			}
		}
	}
	
	return 0;
}
