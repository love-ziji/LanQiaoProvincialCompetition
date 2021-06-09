#include<iostream>
using namespace std;

int main()
{
	double a,b,sum=0;
	for(int i=0;i<50;i++) {
		cin>>a>>b;
		sum+=a*b*0.01;
	}
	cout<<sum<<endl;
	
	return 0;
}
