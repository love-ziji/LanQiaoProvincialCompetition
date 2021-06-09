#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	int sum=0;
	do {
		int x=a[3]*100+a[4]*10+a[5]; //DEF
		int y=a[6]*100+a[7]*10+a[8]; //GHI
		if(fabs(a[0]+(a[1]*y+a[2]*x)*1.0/(a[2]*y) - 10) < 1e-5) {
			sum++;
		}
	} while(next_permutation(a,a+9));
	cout<<sum<<endl;
	
	return 0;
}
