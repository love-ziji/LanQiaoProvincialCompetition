#include<iostream>
using namespace std;
const int N=10001;

int p[N],value[N],d[N];

int find(int x) {
	if(p[x]!=x) {
		int t=p[x];
		p[x]=find(p[x]);
		d[x]+=d[t];
	}
	return p[x];
}

void merge(int x,int y) {
	int px=find(x);
	int py=find(y);
	if(px!=py) {
		d[px]+=value[px]-value[py];
		p[px]=py;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		p[i]=i;
	}
	int op,a,b;
	while(m--) {
		cin>>op>>a>>b;
		if(op==1) {
			merge(a,b);
		}
		else {
			value[find(a)]+=b;
		}
	}
	for(int i=1;i<=n;i++) {
		cout<<value[find(i)]+d[i]<<' ';
	}
	
	return 0;
}
