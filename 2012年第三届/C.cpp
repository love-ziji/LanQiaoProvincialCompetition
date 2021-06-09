#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	for(int a=1;a<=20;a++) {
		for(int b=1;b<a;b++) {
			for(int c=1;c<b;c++) {
				for(int d=1;d<c;d++) {
					//浮点数比较大小
					if(fabs(1.0/a+1.0/b+1.0/c+1.0/d-1) <= 1e-5) {
						cout<<a<<','<<b<<','<<c<<','<<d<<",0"<<endl;
					}
				}
			}
		}
	}
	
	return 0;
}
