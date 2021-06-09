#include<iostream>
using namespace std;

int main()
{
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++) {
		if(str[i+1]>='2' && str[i+1]<='9') {
			for(int j=0;j<str[i+1]-'0';j++) {
				cout<<str[i];
			}
			i++;
		} else {
			cout<<str[i];
		}
	}
	
	return 0;
}
