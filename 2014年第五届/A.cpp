#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	for(int i=0;i<=82.3/2.3;i++) {
		for(int j=i+1;j<=82.3/1.9;j++) {
			if(fabs(i*2.3+j*1.9-82.3) <= 1e-5) {
				cout<<i<<endl;
			}
		}
	}
	
	return 0;
} 
