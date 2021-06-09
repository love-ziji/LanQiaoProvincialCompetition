#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int score,num1=0,num2=0;
	for(int i=0;i<n;i++) {
		cin>>score;
		if(score>=60) {
			num1++;
		}
		if(score>=85) {
			num2++;
		}
	}
	cout<<round(num1*100.0/n)<<'%'<<endl;
	cout<<round(num2*100.0/n)<<'%'<<endl;
//	cout<<int(num1*100.0/n+0.5)<<'%'<<endl;
//	cout<<int(num2*100.0/n+0.5)<<'%'<<endl;

	return 0;
}
