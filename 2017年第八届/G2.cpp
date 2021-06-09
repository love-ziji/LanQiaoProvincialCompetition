#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct {
	int year,month,day;
} Date;

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int year(int y) {
	if(y >= 60) {
		y+=1900;
	}
	else {
		y+=2000;
	}
	return y;
}

bool compare(Date a,Date b) {
	if(a.year != b.year) {
		return a.year < b.year;
	}
	if(a.month != b.month) {
		return a.month < b.month;
	}
	return a.day < b.day;
}

int f(Date d) {
	if(d.year%4==0&&d.year%100!=0 || d.year%400==0) {
		days[2]=29;
	}
	else {
		days[2]=28;
	}
	if(d.month == 0 || d.month > 12) {
		return 0;
	}
	if(d.day == 0 || d.day > days[d.month]) {
		return 0;
	}
	return 1;
}

int main()
{
	int aa,bb,cc;
	scanf("%d/%d/%d",&aa,&bb,&cc); //巧用scanf
	int aa2=year(aa);
	int cc2=year(cc);
	Date date[3]={{aa2,bb,cc},{cc2,aa,bb},{cc2,bb,aa}};
	sort(date,date+3,compare);
	int i=0;
	while(i<3) {
		if(date[i].year==date[i+1].year && date[i].month==date[i+1].month && date[i].day==date[i+1].day) {
			date[i].year=0; //通过设置标志去重，先排序再去重
		}
		i++;
	}
	for(i=0;i<3;i++) {
		if(date[i].year && f(date[i])) {
			printf("%02d-%02d-%02d\n",date[i].year,date[i].month,date[i].day); //巧用printf 
		}
	}
	
	return 0;
}
