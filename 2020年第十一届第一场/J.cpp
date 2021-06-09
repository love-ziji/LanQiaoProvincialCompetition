#include<iostream>
using namespace std;
const int N=10001;

int p[N],ans[N];

int find(int x) {
	return p[x] == x ? p[x] : (p[x]=find(p[x])); //Â·¾¶Ñ¹Ëõ 
}

void merge(int x,int y) {
	int px=find(x);
	int py=find(y);
	if(px!=py) {
		p[px]=py;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) { //³õÊ¼»¯ 
		p[i]=i;
	}
	int op,a,b;
	while(m--) {
		cin>>op>>a>>b;
		if(op==1) {
			merge(a,b);
		}
		else {
			for(int i=1;i<=n;i++) {
				if(find(i)==find(a)) {
					ans[i]+=b;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) {
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
