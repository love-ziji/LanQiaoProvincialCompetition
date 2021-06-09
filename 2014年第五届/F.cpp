#include<iostream>
using namespace std;

int main()
{
	int sum=0;
	for(int a=1;a<10;a++) {
		for(int b=1;b<10;b++) {
			if(a != b) {
				for(int c=1;c<10;c++) {
					for(int d=1;d<10;d++) {
						if(c!=d && a*c*(b*10+d)==b*d*(a*10+c)) {
							sum++;
						}
					}
				}
			}
		}
	}
	cout<<sum<<endl;
	
	return 0;
}
