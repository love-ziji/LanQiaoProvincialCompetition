#include<iostream>
using namespace std;

int fun(int num,int step) {
	if(num > 39) {
		return 0;
	}
	if(num==39 && step%2==0) {
		return 1;
	}
	
	return fun(num+1,step+1)+fun(num+2,step+1);
}

int main()
{
	cout<<fun(0,0)<<endl;
	
	return 0;
}
