#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int numArr[10] ={0,1,2,3,4,5,6,7,8,9};
	do {
		if(numArr[0]!=0 && numArr[4]!=0) {
			int left=numArr[0]*10000+numArr[1]*1000+numArr[2]*100+numArr[3]*10+numArr[4];
			int right=numArr[4]*10000+numArr[3]*1000+numArr[2]*100+numArr[1]*10+numArr[0];
			for(int t=0;t<10;t++) {
				if(left*t == right) {
					cout<<left<<endl;
					return 0;
				}
			}
		}
	} 
	while(next_permutation(numArr,numArr+10)); //È«ÅÅÁÐº¯Êýnext_permutation()
	
	return 0;
}
