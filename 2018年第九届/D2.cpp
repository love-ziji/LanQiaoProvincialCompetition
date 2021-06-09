#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int k=1;
	while(pow(k,3)+5*k < 6000) {
		k++;
	}
	cout<<k<<endl;
	
	return 0;
}
