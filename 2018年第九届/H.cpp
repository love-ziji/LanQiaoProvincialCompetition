#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int N=100001;

// 帖子结构体，保存帖子的id和收到的赞的数量 
typedef struct {
	int id,num;
} Log;

bool compare(Log a,Log b) {
	return a.num>b.num;
}

int main()
{
	int n,d,k;
	Log log[N];
	for(int i=0;i<N;i++) {
		log[i].id=i;
		log[i].num=0;
	}
	vector< vector<int> > time(N); //保存每个帖子收到赞的时间 
	set<int> ans; //保存热帖id，使用set自动排序 
	cin>>n>>d>>k;
	int ts,id,maxid=0;
	for(int i=0;i<n;i++) {
		cin>>ts>>id;
		if(id > maxid) {
			maxid=id;
		}
		log[id].num++;
		time[id].push_back(ts);
	}
	sort(log,log+maxid+1,compare); //以收到的赞的数量对帖子排序 
	for(int i=0;i<=maxid && log[i].num>=k;i++) {
		int f=0;
		sort(time[log[i].id].begin(),time[log[i].id].end()); //将收到赞的时间排序 
		for(int j=0;j<time[log[i].id].size();j++) {
			int q=j;
			while(time[log[i].id][q]-time[log[i].id][j]<d && q<time[log[i].id].size()) {
				if(q-j+1>=k) { //判断是否是热帖 
					ans.insert(log[i].id);
					f=1;
					break;
				}
				q++;
			}
			if(f) {
				break;
			}
		}
	}
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++) {
		cout<<*it<<'\n'; //用'\n'代替endl提高效率 
	}
	
	return 0;
}
