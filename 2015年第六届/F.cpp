#include<iostream>
using namespace std;

int main()
{
	for(int i=1;i<49-1;i++) {
		for(int j=i+2;j<49;j++) {
//			int x=(1+i-1)*(i-1)/2;
//			int y=(i+2+j-1)*(j-1-i-1)/2;
//			int z=(j+2+49)*(49-j-1)/2;
//			if(x+i*(i+1)+y+j*(j+1)+z == 2015) {
//				cout<<i<<endl;
//			}
			int sum=0;
			for(int k=1;k<50;k++) {
				if(k==i || k==j) {
					sum+=k*(k+1);
					k++;
				}
				else {
					sum+=k;
				}
			}
			if(sum == 2015) {
				cout<<i<<endl;
			}
		}
	}
	
	return 0;
}
