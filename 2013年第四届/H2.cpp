#include<iostream>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int sum=0;
    for(int i=0;i<str2.size();i++) {
        if(str1[i] != str2[i]) {
            if(str1[i+1] == '*') {
            	str1[i+1]='o';
            } else {
                str1[i+1]='*';
            }
            sum++;
        }
    }
    cout<<sum<<endl;
    
    return 0;
}
