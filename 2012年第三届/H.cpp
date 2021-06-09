#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[6]={0};
	string str;
	for(int i=0;i<n;i++) {
		cin>>str;
		//以字符为单位处理字符串
		for(int j=0;j<str.size();j++) {
			a[j%6]+=str[j];
		}
		for(int j=0;j<6;j++) {
			while(a[j]/10) {
				int sum=0;
				while(a[j]) {
					sum+=a[j]%10;
					a[j]/=10;
				}
				a[j]=sum;
			}
			cout<<a[j];
			a[j]=0;
		}
	}
	
	return 0;
 } 
