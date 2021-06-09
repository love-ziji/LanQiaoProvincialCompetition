#include<iostream>
using namespace std;

int main()
{
	int sum=0;
	for(int a=0;a<=4;a++)
		for(int b=0;b<=4;b++)
			for(int c=0;c<=4;c++)
				for(int d=0;d<=4;d++)
					for(int e=0;e<=4;e++)
						for(int f=0;f<=4;f++)
							for(int g=0;g<=4;g++)
								for(int h=0;h<=4;h++)
									for(int i=0;i<=4;i++)
										for(int j=0;j<=4;j++)
											for(int k=0;k<=4;k++)
												for(int m=0;m<=4;m++)
													for(int n=0;n<=4;n++)
														if(a+b+c+d+e+f+g+h+i+j+k+m+n == 13)
															sum++;
	cout<<sum<<endl;
	
	return 0;
} 
