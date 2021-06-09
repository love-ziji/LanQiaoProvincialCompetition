#include<iostream>
#include<queue>
using namespace std;
const int Nx=30,Ny=50;

typedef struct Point {
	int x,y;
	string path;
	Point(int a,int b,string str) {
		x=a;
		y=b;
		path=str;
	}
} point;

int m[30][50];
int vis[30][50]={0};
int dis[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char dis_ch[4]={'D','L','R','U'};

void bfs() {
	queue<point> q;
	point p(0,0,"");
	q.push(p);
	vis[0][0]=1;
	while(!q.empty()) {
		point t=q.front();
		q.pop();
		if(t.x==Nx-1 && t.y==Ny-1) {
			cout<<t.path<<endl;
			break;
		}
		for(int i=0;i<4;i++) {
			int tx=t.x+dis[i][0];
			int ty=t.y+dis[i][1];
			if(tx>=0 && ty>=0 && tx<Nx && ty<Ny) {
				if(!m[tx][ty] && !vis[tx][ty]) {
					point t2(tx,ty,t.path+dis_ch[i]);
					q.push(t2);
					vis[tx][ty]=1;
				}
			}
		}
	}
}

int main()
{
	char ch;
	for(int i=0;i<Nx;i++) {
		for(int j=0;j<Ny;j++) {
			cin>>ch;
			m[i][j]=ch-'0';
		}
	}
	bfs();

	return 0; 
}
