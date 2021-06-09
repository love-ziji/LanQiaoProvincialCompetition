#include<iostream>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int n=str.size();
	str=' '+str;
	long long ans=0;
	int last[26]={0};
	for(int i=1;i<=n;i++) {
		ans+=1LL*(i-last[str[i]-'a'])*(n-i+1);
		last[str[i]-'a']=i;
	}
	cout<<ans<<endl;
	
	return 0;
}
