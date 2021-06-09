#include<iostream>
using namespace std;

int main()
{
	unsigned long long a[100]={0,1};
	for(int i=2;i<100;i++) {
		a[i]=a[i-1]+a[i-2];
		cout<<i<<' '<<a[i]<<endl; //a[94]越界
	}
	unsigned long long x=a[88],y=a[89];
	// 模拟手算除法：先整除，然后用余数乘以10继续整除
	for(int i=1;i<=102;i++) {
		cout<<x/y;
		x=(x%y)*10; //乘10可能导致越界，测试得x=a[88],y=a[89]，但只能精确到小数点后36位
	}
	
	return 0;
}
