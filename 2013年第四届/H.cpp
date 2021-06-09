#include<iostream>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int n=-1,sum=0; //n²»ÄÜÈ¡0 
    for(int i=0;i<str1.size();i++) {
        if(str1[i] != str2[i]) {
            if(n != -1) {
                sum+=i-n;
                n=-1;
            } else {
                n=i;
            }
        }
    }
    cout<<sum<<endl;
    
    return 0;
}
