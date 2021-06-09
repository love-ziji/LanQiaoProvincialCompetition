#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
set<int> ans;

void f(int year,int month,int day) {
	if(month == 0 || month > 12) {
		return;
	}
	if(day == 0 || day > days[month]) {
		return;
	}
	if(year >= 60) {
		year+=1900;
	}
	else {
		year+=2000;
	}
	if(month == 2 && day == 29 && !(year%4==0&&year%100!=0 || year%400==0)) { //2月29日出现在非润年
		return;
	}
	ans.insert(year*10000+month*100+day);
}

int main()
{
	string dateStr;
	cin>>dateStr;
	int t=0,k=0,date[3];
	for(int i=0;i<=8;i++) {
		if(i%3 != 2) {
			t*=10;
			t+=dateStr[i]-48;
		}
		else {
			date[k++]=t;
			t=0;
		}
	}
	f(date[0],date[1],date[2]); //年月日
	f(date[2],date[0],date[1]); //月日年
	f(date[2],date[1],date[0]); //日月年
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++) {
		int day=*it%100;
		int month=*it/100%100;
		int year=*it/10000;
		cout<<year<<'-';
		if(month < 10) {
			cout<<'0'<<month<<'-';
		}
		else {
			cout<<month<<'-';
		}
		if(day < 10) {
			cout<<'0'<<day<<endl;
		}
		else {
			cout<<day<<endl;
		}
	}
	
	return 0;
}
