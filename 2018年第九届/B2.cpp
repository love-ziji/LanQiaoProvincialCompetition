#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;

int main()
{
	int a;
	for(int i=1;i<=10;i++) {
		for(int j=1;j<=16;j++) {
			for(int k=1;k<=2;k++) {
				cin>>a;
				bitset<8> b(a);
				cout<<b.to_string();
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	long long ans=pow(9,9);
	cout<<ans<<endl;
	return 0;
}
