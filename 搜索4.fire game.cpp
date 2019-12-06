#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
char Map[15][15];
int vis[20][20];
int dis[20][20];
int n , m , temp , ret;
int num = 1;
struct node
{
	int x;
	int y;
	node(int x , int y) : x(x) , y(y){}
};
int dir[4][2] = {0 , 1 , 1 , 0 , 0 , -1 , -1 , 0};
queue<node> Q;
int bfs(int a , int b , int x , int y)
{
	memset(dis , INF , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	dis[a][b] = 0; dis[x][y] = 0;
	vis[a][b] = 1; vis[x][y] = 1;
	Q.push(node(a , b));
	Q.push(node(x , y));
	while(!Q.empty())
	{
		node u = Q.front();
		Q.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			int xx = u.x + dir[i][0];
			int yy = u.y + dir[i][1];
			if(xx >= n || xx < 0 || yy >= m || yy < 0 || Map[xx][yy] == '.' || vis[xx][yy] == 1)continue;
			
				dis[xx][yy] = dis[u.x][u.y] + 1;
				vis[xx][yy] = 1;
				Q.push(node(xx , yy));
		}
	}
	 ret = 0;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(Map[i][j] == '#')
			{
				ret = max(ret , dis[i][j]);
			}
		}
	}
	return ret;
}
int main()
{
	int T ;
	scanf("%d" , &T);
	while(T--)
	{
		while(!Q.empty())Q.pop();
		int ans = INF , temp;
		scanf("%d %d" , &n , &m);
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%s" , Map[i]);
		}
			for(int i = 0 ; i < n ; i++)
			{
				for(int j = 0 ; j < m ; j++)
				{
					if(Map[i][j] == '#')
					{
						for(int k = 0 ; k < n ; k++)
						{
							for(int l = 0 ; l < m ; l++)
							{
								if(Map[k][l] == '#')
								{
									temp = bfs(i , j , k , l);
									ans = min(ans ,temp);
								}
							}
						}
					}
				}
			}
			
			if(ans == INF)
			{
				printf("Case %d: -1\n" , num++);
			}
			else
			{
				printf("Case %d: %d\n" , num++ , ans);
			}
	}
	return 0;
}
