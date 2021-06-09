#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int n=str.size();
	int ans=0;
	for(int i=0;i<n;i++) {
		unordered_set<char> s;
		for(int j=i;j<n;j++) {
			s.insert(str[j]);
			ans+=s.size();
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
