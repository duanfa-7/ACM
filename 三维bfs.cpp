#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm> 
#include <queue>
using namespace std;
int l , r , c;
int dx[6] = {0 , 0 , 0 , 0 , 1 , -1};
int dy[6] = {0 , 0 , 1 , -1 , 0 , 0};
int dz[6] = {1 , -1 , 0 , 0 , 0 , 0};
const int maxn = 33;
char data[maxn][maxn][maxn];
//int vis[maxn][maxn][maxn];
struct node
{
	int x , y , z , s;
}start;


int judge(int x , int y , int z)
{
	if(data[x][y][z] == '#')return 0;
	else if(x >= l || x < 0 || y >= r || y < 0 || z >= c || z < 0)return 0;
//	else if(vis[x][y][z] == 1)return 0; 
	return 1;
}
int bfs(int x , int y , int z , int s)
{
	data[x][y][z] == '#';
	start.x = x;
	start.y = y;
	start.z = z;
	start.s = 0;
	queue<node> Q;
	Q.push(start);
	while(!Q.empty())
	{
		 node now;
		 now = Q.front();
		 Q.pop();
		//cout <<bfs(now.x ,now.y , now.z ,now.s) << endl;
	
		for(int i = 0 ; i < 6 ; i++)
		{
			 node next ;
			 next.x = now.x + dx[i];
			 next.y = now.y + dy[i];
			 next.z = now.z + dz[i];
		
			if(judge(next.x , next.y , next.z))
			{
				next.s = now.s + 1;	
				if( data[next.x][next.y][next.z] == 'E')
				{
					return next.s;
				}
				Q.push(next);
				data[next.x][next.y][next.z] = '#';
			}
			
		 } 		
	}
	return -1;
}
int main()
{
	while(~scanf("%d%d%d" , &l  , &r , &c))
	{
//	memset(vis , 0 , sizeof(vis));
//	while(!Q.empty())
//	{
//		Q.pop();
//	}
		if(l == 0 && r == 0 && c == 0)
		{
			break;
		}
		for(int i = 0 ; i < l ; i++)
		{
			for(int j = 0 ; j < r ; j++)
			{
				
				for(int k = 0 ; k < c ; k++)
				{
					cin >> data[i][j][k];
					if(data[i][j][k] == 'S')
					{
					start.x = i;start.y = j; start.z = k;
					}
		}
			}
		}
//		start.s = 0;
//		Q.push(start);
	//	vis[start.x][start.y][start.z] = 1;
		int ans = bfs(start.x , start.y , start.z , 0);
		if(ans == -1)
		{
			printf("Trapped!\n");
		}
		else
		{
			printf("Escaped in %d minute(s).\n" , ans);
		}
		
	}

	return 0;
 } 
