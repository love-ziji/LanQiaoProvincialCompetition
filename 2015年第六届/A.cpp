#include<iostream>
using namespace std;

int main()
{
	int sum=0;
	for(int a=1;a<10;a++) {
		if(a != 4) {
			for(int b=0;b<10;b++) {
				if(b != 4) {
					for(int c=0;c<10;c++) {
						if(c != 4) {
							for(int d=0;d<10;d++) {
								if(d != 4) {
									for(int e=0;e<10;e++) {
										if(e != 4) {
											sum++;
										}
									}
								}
							}
						}
					}
				}
			}	
		}
	}
	cout<<sum<<endl;
	
	return 0;
} 
