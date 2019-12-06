#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x3f3f3f3f
const int maxn = 150; 
using namespace std;
int Map[maxn][maxn];
int main()
{
	int t , n , m , a , b , ans , maxx;
	while(cin >> t && t)
	{
		int flag = INF; 
		memset(Map , INF , sizeof(Map)); 
		for(int i = 1 ; i <= t ; i++) 
		{
			cin >> n;
			while(n--)
			{
				cin >> a >> b;
				Map[i][a] = b;
			}
		}
		for(int i = 1 ; i <= t ; i++)
		{
			for(int j = 1 ; j <= t ; j++)
			{
				for(int k = 1 ; k <= t ; k++)
				{
					if(Map[j][k] > Map[j][i] + Map[i][k])
					{
						Map[j][k] = Map[j][i] + Map[i][k];
					}
				}
			}
		}
		for(int i = 1 ; i <= t ; i++)
		{
			int big = 0;
			for(int j = 1 ; j <= t ; j++)
			{
				if(i == j)continue;
				if(big < Map[i][j])
				{
					big = Map[i][j];
				}
			}
			cout << "big = " << big << endl;
			if(flag > big)
			{
				flag = big;
				ans = i;
			}
		}
		for(int i = 1 ; i <= t ; i++)
		{
			for(int j = 1 ; j <= t ; j++)
			{
				printf("Map[%d][%d] = %d          " , i , j , Map[i][j]);
			}
			cout << endl;
		}
		if(flag == INF)
		{
			printf("disjoint\n");
		}
		else
		{
			printf("%d %d\n" , ans , flag);
		}
	}
	return 0;
}
