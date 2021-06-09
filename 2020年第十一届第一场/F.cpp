#include<cstdio>
using namespace std;

int main()
{
	long long n;
	scanf("%lld",&n);
	while(n) {
		printf("%lld ",n);
		n>>=1;
	}
	
	return 0;
}
