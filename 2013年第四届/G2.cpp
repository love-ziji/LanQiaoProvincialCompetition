#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,i=0,a[10000];
	cin>>n;
	while(n--) {
		while(cin>>a[i++]) {
			if(cin.get() == '\n') { //每行数据以换行符'\n'结束 
				break;
			}
		}
	}
	sort(a,a+i);
	int x,y; //x为断号ID，y为重号ID
	for(int j=0;j<i;j++) {
		if(a[j]+1 < a[j+1]) {
			x=a[j]+1;
		}
		if(a[j] == a[j+1]) {
			y=a[j];
		}
	}
	cout<<x<<' '<<y<<endl;
	
	return 0;
 } 
