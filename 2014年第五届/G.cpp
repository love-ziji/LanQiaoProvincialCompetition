#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[9]={2,4,5,6,7,9,10,11,12};
	do {
		int sum1=1+a[0]+a[3]+a[5];
		int sum2=1+a[1]+a[4]+a[8];
		int sum3=a[5]+a[6]+a[7]+a[8];
		int sum4=3+a[6]+a[3]+8;
		int sum5=3+a[7]+a[4]+a[2];
		int sum6=8+a[0]+a[1]+a[2];
		if(sum1==26 && sum2==26 && sum3==26 && sum4==26 && sum5==26 && sum6==26) {
			cout<<a[3]<<endl;
			break;
		}
	} while(next_permutation(a,a+9));
	
	return 0;
}
