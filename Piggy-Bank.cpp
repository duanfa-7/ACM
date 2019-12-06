#include <stdio.h>
#include <iostream>
using namespace std;
#define INF 9999999
const int maxn = 50000+100;
int dp[maxn];
struct node 
{
	int p ;
	int w;
}a[maxn];
int main()
{
	int t , e , f , n;
	scanf("%d" , &t);
	while(t--)
	{
		for(int i = 0 ; i < maxn ; i++)
		{
			dp[i] = INF;
		}
		dp[0]=0;
		scanf("%d %d %d" , &e , &f , &n);
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d %d" , &a[i].p , &a[i].w);
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = a[i].w ; j <= f-e ; j++)
			{
				dp[j] = min(dp[j] , dp[j-a[j].w]+a[i].p);
			}
		}
		if(dp[f-e] != INF)
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n" , dp[f-e]);
		}
		else
		{
			printf("This is impossible.\n");
		}
	}
	return 0;
}
