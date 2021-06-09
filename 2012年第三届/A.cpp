#include<iostream>
using namespace std;

int main()
{
	int x,y,t=120;
	cin>>x>>y;
	int n=1,f=0;
	while(n <= t) {
		if(f==0 && n%2==1) {
			y-=x;
			if(y <= 0) {
				f=1;
			}
		}
		if(f==0 && n%4==0) {
			y*=2;
		}
		if(n%6 == 0) {
			x*=2;
		}
		n++;
	}
	cout<<"x="<<x<<endl;
	if(f == 0) {
		cout<<"y="<<y<<endl;
	} else {
		cout<<"y=0"<<endl;
	}
	
	return 0;
 }
