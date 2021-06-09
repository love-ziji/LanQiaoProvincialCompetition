#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long x,y;
	cin>>x>>y;
	long long m=max(abs(x),abs(y)),ans;
	if(y > x) {
		ans=(4+4*(m-1))*(m-1)+x+y+2*m;
	}
	else {
		ans=(4+4*m)*m-x-y-2*m;
	}
	cout<<ans<<endl;
	
	return 0;
}
