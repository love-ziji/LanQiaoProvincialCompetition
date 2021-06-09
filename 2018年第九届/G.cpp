#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int x,y,x2=0,y2=0;
	int dis[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
	long long ans=0,n=0,step=1;
	cin>>x>>y;
	while(x2!=x || y2!=y) {
		ans+=step;
		int d=(n++)%4; //前进方向 
		x2+=step*dis[d][0];
		y2+=step*dis[d][1];
		if(n%2==0) { //步长前进2次就+1 
			step++;
		}
		if(x2==x && y2!=y) { //x相同y不同 
			d=n%4;
			if(dis[d][1]>0 && y-y2>0 && y-y2<=step || dis[d][1]<0 && y2-y>0 && y2-y<=step) { //y2向上走或向下走到y 
				ans+=abs(y-y2);
				break;
			}
		}
		if(y2==y && x2!=x) {
			d=n%4;
			if(dis[d][0]>0 && x-x2>0 && x-x2<=step || dis[d][0]<0 && x2-x>0 && x2-x<=step) {
				ans+=abs(x-x2);
				break;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
