#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6+8;
int main()
{
	int n;
	while(~scanf("%d" , &n))
	{
		ll ans = 0;
		for(int i = 1 ; i <= sqrt(N); i++)
		{
			if(n/i == n%i)
			{
				printf("* %d  *" , i);
			} 
		}
		printf("\n");
	//	printf("%lld\n" , ans);
	}
	return 0;
} 

/*
n%(m+1) == 0 满足即可 
*/