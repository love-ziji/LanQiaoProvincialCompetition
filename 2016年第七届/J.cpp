#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b) {
	return b ? gcd(b,a%b) : a;
}

ll gcd2(ll a,ll b) { //求a、b的公底数
	if(a == b) {
		return a;
	}
	else if(a > b) {
		return gcd2(b,a/b);
	}
	else {
		return gcd2(a,b/a);
	}
}

int main()
{
	set<ll> s; //set元素不能重复且自动从小到大排序
	ll n,t;
	cin>>n;
	for(ll i=0;i<n;i++) {
		cin>>t;
		s.insert(t);
	}
	vector<ll> up,down; //保存分子和分母 
	ll num1,num2,n2=0;
	for(set<ll>::iterator it=--s.end();it!=s.begin();) {
		num1=*it;
		num2=*(--it);
		t=gcd(num1,num2);
		up.push_back(num1/t);
		down.push_back(num2/t);
		n2++;
	}
	ll a=up[0],b=down[0];
	for(int i=1;i<n2;i++) {
		a=gcd2(a,up[i]);
		b=gcd2(b,down[i]);
	}
	cout<<a<<'/'<<b<<endl;
	
	return 0;
}
