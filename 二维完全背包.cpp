#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int INF = 1000000;
int dp[150][150];
struct node 
{
	int v;//��ȡ�ľ���ֵ 
	int w;//��ĵ�����ֵ 
}aqu[150];

int main ()
{
	int n , m , k , s;//����ľ���ֵ�����������Ͷȣ��ֵ�����������ɱ����
	while(~scanf("%d %d %d %d" , &n , &m , &k , &s))
	{
	
	
		for(int i = 1 ; i <= k ; i++)
		{
			scanf("%d %d" , &aqu[i].v , &aqu[i].w);
		}
		memset(dp , 0 , sizeof(dp));
		int ans = INF , flag = 0 , qq;
		for(int i = 1 ; i <= k ; i++)
		{
			for(int j = aqu[i].w ; j <= m ; j++)
			{
				for(int p = 1 ; p <= s ; p++)
				{
					dp[j][p] = max(dp[j][p] , dp[j - aqu[i].w] [p - 1] + aqu[i].v);
					if(dp[j][p] >= n && ans >= j)
					{
						qq = dp[j][p];
						ans = j;
						break;
					}
				}
			}
		}
	
//	printf("qq = %d\n" , qq);
//	printf("ans = %d\n" , ans);
		if(ans == INF)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n" , m - ans);
		}

	}
	
	return 0;
}

