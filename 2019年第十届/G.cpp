#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int n,a[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	vector<int> res;
	int p=0,q=0;
	while(p<n) {
		int sum=0;
		for(int i=0;i<pow(2,q)&&p<n;i++) {
			sum+=a[p++];
		}
		res.push_back(sum);
		q++;
	}
	int maxIndex=0;
	for(int i=1;i<res.size();i++) {
		if(res[i]>res[maxIndex]) {
			maxIndex=i;
		}
	}
	cout<<maxIndex+1<<endl;
	
	return 0;
}
