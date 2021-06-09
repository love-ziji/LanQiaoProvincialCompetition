#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int a=0;a<=sqrt(n);a++) {
		for(int b=a;b<=sqrt(n);b++) {
			if(a*a+b*b <= n) {
				for(int c=b;c<=sqrt(n);c++) {
					int t=a*a+b*b+c*c;
					if(t <= n) {
						int d=sqrt(n-t); //四层循环改为三层循环
						if(t+d*d == n) {
							cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
							return 0;
						}
					}
				}
			}
		}
	}
	
	return 0;
}
