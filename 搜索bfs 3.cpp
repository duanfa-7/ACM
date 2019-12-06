#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <queue>
using namespace std;
int vis[10][10] , data[10][10];
int judge(int n , int m)
{
	if(n > 4 || n < 0 || m > 4 || m < 0)return 0;
	if(vis[n][m] == 1 || data[n][m] == 1)return 0;
	return 1;
}
struct node 
{
	int x;
	int y;
};
node pre[10][10];
queue<node>W;
void bfs(int x , int y)
{
	int way[4][2] = {0 , 1 ,1, 0 , 0 , -1 , -1 , 0};
	pre[x][y].x == 0 ;
	pre[x][y].y == 0 ;
	queue<node> Q;	
	node now;
	now.x = x;
	now.y = y;
	vis[x][y] = 1;
	Q.push(now);
	while(!Q.empty())
	{
		now = Q.front();
		if(now.x == 4 && now.y == 4)
		{
			return;
		}
		node next;
		Q.pop();
		for(int i = 0 ; i < 4; i++)
		{
			next.x = now.x + way[i][0];
			next.y = now.y + way[i][1]; 
			if(judge(next.x , next.y))
			{
				vis[next.x][next.y] = 1;
				pre[next.x][next.y] = now;				
				Q.push(next);	
			}
		}
	}
}
void output(int x , int y)
{
	if(x == 0 && y == 0)
	{
		printf("(0, 0)\n");
		return ;
	}
	output(pre[x][y].x , pre[x][y].y);
	printf("(%d, %d)\n" , x , y);
}
int main()
{
	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			cin>> data[i][j];
		}
	}
bfs(0 , 0);
output(4 , 4);
	return 0;
 } 
