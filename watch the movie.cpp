#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1111; 
int dp[maxn][maxn];
struct node 
{
	int time;
	int val;
}vv[maxn];
int main ()
{
	int T , N , M , L ;//想买的数量 ， 商店卖的数量 ， 允许看的时间 
	scanf("%d" , &T);

	while(T--)
	{
		int min = -99999; 
		scanf("%d %d %d" , &N , &M , &L);
		for(int i = 0 ; i < N ; i++)
		{
			scanf("%d %d" , &vv[i].time , &vv[i].val);
		}
		for(int i = 0 ; i <= M ; i++)
		{
			for(int j = 0 ; j <= L ; j++)
			{
				if(i == 0)
				{
					dp[i][j] = 0;
				 } 
				 else
				 {
				 	dp[i][j] = min;
				 }
				
			}
		}
		
		for(int i = 0 ; i < N ; i++)
		{
			for(int j = M ; j >= 1 ; j--)
			{
				for(int k = L ; k >= vv[i].time ; k--)
				{
					dp[j][k] = max(dp[j][k] , dp[j-1][k - vv[i].time] + vv[i].val);
				
				}
			}
		}
		if(dp[M][L] < 0)
		{
			dp[M][L] = 0;
		}
		printf("%d\n" , dp[M][L]);
	}
		
	return 0 ;
}
