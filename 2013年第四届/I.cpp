#include<iostream>
#include<algorithm>
using namespace std;

int arr[9]={1,2,3,4,5,6,7,8,9};

int getNum(int x,int y) { //由数组求出该数 
	int num=0;
	for(int i=x;i<=y;i++) {
		num=num*10+arr[i];
	}
	return num;
}

int main()
{
	int n,sum=0;
	cin>>n;
	do {
		for(int i=0;i<7;i++) { //a的位数最大为7位 
			for(int j=i+1;j<8;j++) { //c的位数不能为0
				if(j-i >= 8-j) {
					int a=getNum(0,i); //a=arr[0]...arr[i]
					int b=getNum(i+1,j); //b=arr[i+1]...arr[j]
					int c=getNum(j+1,8); //c=arr[j+1]..a[8]
					if(b%c==0 && a+b/c==n) {
						sum++;
					}
				}
			}
		}
	} while(next_permutation(arr,arr+9));
	cout<<sum<<endl;
	
	return 0;
} 
