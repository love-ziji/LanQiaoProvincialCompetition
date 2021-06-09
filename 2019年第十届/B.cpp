#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<char> s;
	int n;
	cin>>n;
	while(n) {
		s.push('A'+n%26-1);
		n/=26;
	}
	while(!s.empty()) {
		cout<<s.top();
		s.pop();
	}
	
	return 0;
}
