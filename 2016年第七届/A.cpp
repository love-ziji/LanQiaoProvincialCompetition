#include<iostream>
using namespace std;

int main()
{
	int sum=0,t=0;
	for(int i=1;i<=100;i++) {
		t+=i;
		sum+=t;
	}
	cout<<sum<<endl;
	
	return 0;
}
