#include<iostream>
#include<cstring>
using namespace std;
#define lowbit(x) x&(-x) //lowbit(x)=2^k,k为x的二进制中从最低位到高位连续零的长度

int maxh=-1,tree[1000001]; //树状数组下标为身高，原数组保存每个身高的小朋友个数

void update(int x,int val) { //更新树状数组
	while(x <= maxh+1) {
		tree[x]+=val;
		x+=lowbit(x);
	}
}

int getsum(int x) { //通过树状数组计算原数组前x项和，这里即为小于等于h[i]的数据个数
	int sum=0;
	while(x > 0) {
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}

int main()
{
	int n,h[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>h[i];
		maxh=max(maxh,h[i]);
	}
	long long swap[100000];
	for(int i=0;i<n;i++) {
		update(h[i]+1,1); //为什么是h[i]+1？树状数组下标从1开始，而h[i]可能为0
		swap[i]=i+1-getsum(h[i]+1); //计算左边比其大的数据个数，等于左边数据总个数-小于等于其的数据个数
	}
	memset(tree,0,sizeof(tree));
	for(int i=n-1;i>=0;i--) {
		update(h[i]+1,1);
		swap[i]+=getsum(h[i]); //计算右边比其小的数据个数
	}
	long long res=0;
	for(int i=0;i<n;i++) {
		res+=(1+swap[i])*swap[i]/2;
	}
	cout<<res<<endl;
	
	return 0;
}
