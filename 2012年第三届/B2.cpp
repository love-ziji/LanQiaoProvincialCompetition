#include<iostream>
using namespace std;

int main()
{
	for(int a=1;a<10;a++) { //A和E为首位不能为零
		for(int b=0;b<10;b++) {
			for(int c=0;c<10;c++) {
				for(int d=0;d<10;d++) {
					for(int e=1;e<10;e++) {
						//两两互不相同
						if(a!=b && a!=c && a!=d && a!=e && b!=c && b!=d && b!=e && c!=d && c!=e && d!=e) {
							for(int t=0;t<10;t++) {
								int left=a*10000+b*1000+c*100+d*10+e;
								int right=e*10000+d*1000+c*100+b*10+a;
								if(left*t == right) {
									cout<<left<<endl;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
 }
