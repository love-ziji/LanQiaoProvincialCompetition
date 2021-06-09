#include<iostream>
using namespace std;

int main()
{
	int year=2000,month=1,day=1,week=6;
	int monthDay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int ans=0;
	while(year<=2020) {
		if(year%4==0&&year%100!=0 || year%400==0) {
			monthDay[2]=29;
		}
		else {
			monthDay[2]=28;
		}
		while(month<=12) {
			while(day<=monthDay[month]) {
				if(day==1 || week==1) {
					ans+=2;
				}
				else {
					ans+=1;
				}
				if(year==2020 && month==10 && day==1) {
					cout<<ans<<endl;
					return 0;
				}
				day++;
				week=(week+1)%7; //星期天时week=0，不影响结果 
			}
			month++;
			day=1;
		}
		year++;
		month=1;
	}
	
	return 0;
}
