#include<iostream>
using namespace std;

int main()
{
	int ans=0;
	for(int i=1;i<=2020;i++) {
		int t=i;
		while(t) {
			if(t%10==2) {
				ans++;
			}
			t/=10;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
