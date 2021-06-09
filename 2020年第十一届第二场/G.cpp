#include<iostream>
#include<sstream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int year,month,day;
	year=n/10000;
	month=n%10000/100;
	day=n%100;
	day++;
	string date,date1,date2,yearStr,monthStr,dayStr;
	int monthDay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int f1=0,f2=0;
	while(1) {
		if(year%4==0&&year%100!=0 || year%400==0) {
			monthDay[2]=29;
		}
		else {
			monthDay[2]=28;
		}
		stringstream yearSS;
		yearSS<<year;
		yearSS>>yearStr;
		while(month<=12) {
			stringstream monthSS;
			monthSS<<month;
			monthSS>>monthStr;
			if(month<10) {
				monthStr="0"+monthStr;
			}
			while(day<=monthDay[month]) {
				stringstream daySS;
				daySS<<day;
				daySS>>dayStr;
				if(day<10) {
					dayStr="0"+dayStr;
				}
				date=yearStr+monthStr+dayStr;
				//下一个回文日期
				if(!f1 && date[0]==date[7] && date[1]==date[6] && date[2]==date[5] && date[3]==date[4]) {
					date1=date;
					f1=1;
				}
				//下一个 ABABBABA 型的回文日期
				if(date[0]!=date[1] && date[2]==date[0] && date[5]==date[0] && date[7]==date[0] && date[3]==date[1] && date[4]==date[1] && date[6]==date[1]) {
					date2=date;
					f2=1;
				}
				if(f1 && f2) {
					cout<<date1<<endl<<date2<<endl;
					return 0;
				}
				day++;
			}
			month++;
			day=1;
		}
		year++;
		month=1;
	}
	
	return 0;
}
