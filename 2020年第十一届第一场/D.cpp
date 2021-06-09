#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

int main()
{
	stack<int> s1,s2; //s1保存循环深度，s2保存循环次数 
	fstream prog("prog.txt");
	string line;
	int ans=0,k=1; //k为当前总循环次数 
	getline(prog,line); //舍弃第一行 
	while(getline(prog,line)) {
		int space,i; //space为跳格数 
		for(i=0;i<line.size();i++) {
			if(line[i] != ' ') {
				space=i/4;
				break;
			}
		}
		if(line[i]=='R') {
			int num=line[i+7]-'0';
//			if(s1.empty() || space>s1.top()) { //向内循环 
//				k*=num;
//				s1.push(space);
//				s2.push(num);
//			}
//			else { //循环结束 
				while(!s1.empty() && space<=s1.top()) {
					k/=s2.top();
					s1.pop();
					s2.pop();
				}
				k*=num;
				s1.push(space);
				s2.push(num);
//			}
		}
		else {
			int num=line[i+8]-'0';
//			if(space>s1.top()) { //向内循环 
//				ans+=num*k;
//			}
//			else { //循环结束 
				while(!s1.empty() && space<=s1.top()) {
					k/=s2.top();
					s1.pop();
					s2.pop();
				}
				ans+=num*k;
//			}
		}
	}
	prog.close();
	cout<<ans<<endl;
	
	return 0;
}
