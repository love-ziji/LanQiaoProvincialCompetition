#include<iostream>
using namespace std;

int main()
{
	int n,t,minNum=100000,maxNum=0,hash[100001]={0};
	cin>>n;
	while(n--) {
		while(cin>>t) {
			if(t<minNum) {
				minNum=t;
			}
			if(t>maxNum) {
				maxNum=t;
			}
			hash[t]++;
			if(cin.get() == '\n') { //每行数据以换行符'\n'结束 
				break;
			}
		}
	}
	int a,b; //a为断号ID，b为重号ID 
	for(int i=minNum;i<=maxNum;i++) {
		if(hash[i] == 0) {
			a=i;
		}
		if(hash[i] >= 2) {
			b=i;
		}
	}
	cout<<a<<' '<<b<<endl;
	
	return 0;
}
