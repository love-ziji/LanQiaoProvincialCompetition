#include<iostream>
using namespace std;

int main()
{
	int a,num_2=0,num_5=0;
	for(int i=0;i<100;i++) {
		cin>>a;
		while(a%5==0) {
			num_5++;
			a/=5;
		}
		while(a%2==0) {
			num_2++;
			a/=2;
		}
	}
	cout<<min(num_2,num_5)<<endl;
	
	return 0;
}
