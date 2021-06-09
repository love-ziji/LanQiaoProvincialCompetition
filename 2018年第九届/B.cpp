#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int b[8];

void binary(int a) { //计算原码 
	for(int i=7;i>=0;i--) {
		if(a >= pow(2,i)) {
			a-=pow(2,i);
			b[i]=1;
		}
	}
}

int main()
{
	int a;
	for(int i=1;i<=10;i++) {
		for(int j=1;j<=16;j++) {
			for(int k=1;k<=2;k++) {
				memset(b,0,sizeof(b));
				cin>>a;
				if(a >= 0) { //正数 
					binary(a);
				}
				else { //负数 
					binary(-1*a);
					// 计算反码 
					for(int p=0;p<8;p++) {
						b[p]=1-b[p];
					}
					// 计算补码 
					int q=0;
					while(b[q]) {
						b[q++]=0;
					}
					b[q]=1;
				}
				for(int p=7;p>=0;p--) {
					cout<<b[p];
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	long long ans=pow(9,9);
	cout<<ans<<endl;
	
	return 0;
} 
