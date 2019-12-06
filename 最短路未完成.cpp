#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
int main()
{
	int n , m , a , b ,c ,u, min;
	int dis[100] , book[100];
	int Edge[100][100];
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			if(i == j)
			{
				Edge[i][j] = 0;
			}
			else
			{
				Edge[i][j] = INF;
			}
		}
	}
	while(m--)
	{
		scanf("%d %d %d" , &a , &b , &c);
		Edge[a][b] = c;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		dis[i] = Edge[1][i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		book[i] = 0;
	}
	book[1] = 1;
	for(int i = 1 ; i <= n - 1 ; i++)
	{
		min = INF;
		for(int j = 1 ; j <= n ; j++)
		{
			if(book[j] == 0 && dis[j] < INF)
			{
				min = dis[j];
				u = j;
			 } 
		}
		book[u] = 1;
		for(int v = 1 ; v <= n ; v++)
		{
			if(dis[v] > dis[u] + Edge[u][v])
			{
				dis[v] = dis[u] + Edge[u][v];
			}
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		printf("%d " , dis[i]);
		
	}
	return 0;
 } 
