#include<iostream>
#include<vector>
using namespace std;

const int MOD=1e9+7;

int main()
{
	vector<int> can[7]; //can[i]存能与点数i紧贴的点数
	long long top[7],bottom[7]; //top[i]存第n层骰子以点数i为顶面的方案数，bottom[i]存第n层骰子以点数i为底面的方案数
	//初始化 
	for(int i=1;i<=6;i++) {
		top[i]=1; //第1层骰子以点数i为顶面的方案数为1
		for(int j=1;j<=6;j++) {
			can[i].push_back(j);
		}
	}
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++) { //删除不能紧贴的m组点
		cin>>a>>b;
		for(vector<int>::iterator it=can[a].begin();it!=can[a].end();it++) {
			if(*it == b) {
				can[a].erase(it);
				break;
			}
		}
		for(vector<int>::iterator it=can[b].begin();it!=can[b].end();it++) {
			if(*it == a) {
				can[b].erase(it);
				break;
			}
		}
	}
	long long k=4;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=6;j++) {
			bottom[j]=0;
			for(vector<int>::iterator it=can[j].begin();it!=can[j].end();it++) {
				bottom[j]+=top[*it]; //状态转移方程
			}
		}
		for(int j=1;j<=6;j++) {
			top[j]=bottom[(j+3)%6==0 ? 6 : (j+3)%6]%MOD;
		}
		k*=4;
		k%=MOD;
	}
	long long sum=0;
	for(int i=1;i<=6;i++) {
		sum+=top[i];
		sum%=MOD;
	}
	cout<<sum*k%MOD<<endl;
	
	return 0;
}
