#include<iostream>
using namespace std;

int main()
{
	int a[3]={1,1,1};
	int index=3;
	while(index < 20190324) {
		a[index%3]=(a[0]+a[1]+a[2])%10000;
		index++;
	}
	cout<<a[(index-1)%3]<<endl;
	
	return 0;
}
