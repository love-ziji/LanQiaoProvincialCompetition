#include<iostream>
#include<set>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int n=str.size();
	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			set<char> s;
			for(int k=i;k<=j;k++) {
				s.insert(str[k]);
			}
			ans+=s.size();
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
