#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int w,d[2][3];
	cin>>w>>d[0][0]>>d[1][0];
	for(int i=0;i<2;i++) {
		d[i][1]=d[i][0]/w; //计算x坐标
		//计算y坐标
		int t=(d[i][0]%w)==0?w:d[i][0]%w;
		if(d[i][1]%2 == 0) {
			d[i][2]=t; //正向排号
		}
		else {
			d[i][2]=w-t+1; //反向排号
		}
	}
	cout<<abs(d[0][1]-d[1][1])+abs(d[0][2]-d[1][2]); 
	
	return 0;
}
