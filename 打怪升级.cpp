#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[110][110];
struct node 
{
	int aqu;
	int red;
}ah[110];
void init()
{
	for(int i = 0 ; i < 110 ; i++)
	{
		for(int j = 0 ; j < 110 ; j++)
		{
			dp[i][j] = 0;
		}
		
	}
}

int main ()
{
	int n , m , k , s , a , b , ans , vv;
	while(~scanf("%d %d %d %d" , &n , &m , &k , &s))
	{
		init();
		ans = 1000000;
		for(int i = 0 ; i < k ; i++)
		{
			scanf("%d %d" , &ah[i].aqu , &ah[i].red);
		}
		for(int i = 0 ; i < k ; i++)
		{
			for(int l = ah[i].red ; l <=m ; l++)
			{
				for(int p = 0 ; p < s ; p++)
				{
					dp[l][p] = max(dp[l][p] , dp[l - ah[i].red][p-1] + ah[i].aqu);
					if(l < ans && dp[l][p] >= n)
					{
						ans = l;
						break;
					}
				}
			}
			
		}	
		if(ans == 1000000)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",m - ans);
		}
	}

	return 0;
}
