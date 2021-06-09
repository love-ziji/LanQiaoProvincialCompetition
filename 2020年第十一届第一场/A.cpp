#include<iostream>
using namespace std;

int main()
{
	int n=10000;
	int change[2]={-10,5};
	int time=0,k=0;
	while(n) {
		n+=change[k];
		time++;
		if(time%60 == 0) {
			k=1-k;
		}
	}
	cout<<time<<endl;
	
	return 0;
}
