#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[9]={0,2,3,4,5,6,7,8,9}; //a[0]-a[6]分别代表羊、献、瑞、祥、生、辉、气 
	do {
		if(a[3]>=8 && a[2]!=0 && a[5]!=0) {
			int x=1*1000+a[0]*100+a[1]*10+a[2];
			int y=a[3]*1000+a[2]*100+a[4]*10+a[5];
			int z=1*10000+a[0]*1000+a[4]*100+a[2]*10+a[6];
			if(x+y == z) {
				cout<<1<<a[0]<<a[1]<<a[2]<<endl;
				return 0;
			}
		}
	} while(next_permutation(a,a+9));
	
	return 0;
}
