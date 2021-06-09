#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,a[100000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	int minDiff=a[1]-a[0];
	for(int i=2;i<n;i++) {
		int diff=a[i]-a[i-1];
		if(diff<minDiff) {
			minDiff=diff;
		}
	}
	if(minDiff==0) { //d=0 
		cout<<n<<endl;
	} else {
		cout<<(a[n-1]-a[0])/minDiff+1<<endl;
	}
	
	return 0;
}
