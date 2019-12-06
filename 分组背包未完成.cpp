#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 10005;
int dp[maxn];
struct node 
{
	int w;
	int v;
	int gp;
}vv[maxn];
int main ()
{
	int n , m ,ans = 0 , flag;
	scanf("%d %d" , &n , &m);
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d %d %d" , &vv[i].w , &vv[i].v , &vv[i].gp);
	}
	memset(dp , 0 , sizeof(dp));
	for(int k = 0 ; k < n ; k++)
	{
		for(int i = 0 ; i < vv[k].gp ; i++)
		{
			
			for(int j = m ; j >= vv[k].w ; j--)
			{
				dp[j] = max(dp[j] , dp[j - vv[k].w] + vv[k].v);

			}
	//	continue;
		}
	//	printf("777");
	}
	printf("%d" , dp[m]); 
	return 0;
}
/*
7 10000
1 10 30
2 5 50
5 3 100
156 7 30
256 15 105
103 11 108
313 35 1022
*/
