#include<iostream>
#include<set>
using namespace std;
const int N=1000;

int main()
{
	int n;
	cin>>n;
	long long ans=0;
	int lines[N][2];
	int vis[N]={0};
	pair<long double,long double> point;
	for(int i=0;i<n;i++) {
		cin>>lines[i][0]>>lines[i][1];
		set<pair<long double,long double>> points;
		for(int j=0;j<i;j++) {
			if(vis[j]) continue;
			if(lines[i][0]==lines[j][0]) {
				if(lines[i][1]==lines[j][1]) { //重合 
					vis[i]=1;
					break;
				}
				else continue; //平行 
			}
			point.first=(lines[j][1]-lines[i][1])*1.0/(lines[i][0]-lines[j][0]);
			point.second=lines[i][0]*point.first+lines[i][1];
			points.insert(point);
		}
		if(!vis[i]) {
			ans+=points.size()+1;
		}
	}
	cout<<ans+1<<endl;
	
	return 0;
}
