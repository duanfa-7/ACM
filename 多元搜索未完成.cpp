#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
const int maxn = 1008;
using namespace std;
int n , m , flag=0;
char map[maxn][maxn];
int people[maxn][maxn];
int fire[maxn][maxn];
int dist1[maxn][maxn];
int dist2[maxn][maxn];
struct node
{
	int x, y, step;
	
};
int judge(int x , int y)
{
	if(x >= n || x < 0 || y >= m || y < 0 || map[x][y] == '#') return 0;
	return 1;
}
int judge_p(int x,int y,int S)
{
	if(judge(x,y) == 0 || people[x][y] || dist1[x][y] <= S) return 0;
	return 1;
}
int dir[4][2] = {0 , 1 , 1 , 0 , 0 , -1 , -1 , 0};
queue<node> Fire, People;
node now , next;
void bfs_fire()
{	
	while(!Fire.empty())
	{
		now = Fire.front();
		Fire.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if(judge(next.x , next.y) && fire[next.x][next.y] == 0)
			{
				fire[next.x][next.y] = 1;
				
				dist1[next.x][next.y] = now.step + 1;;
				Fire.push(next);
			}
		}
	}
	return ;
}
int ans;
int bfs_people(int x , int y)
{
	people[now.x][now.y] = 1;
	dist2[now.x][now.y] = 0;
	People.push(now);
	while(!People.empty())
	{
		now = People.front();
		People.pop();
		if(now.x == 0 || now.x == n-1 || now.y == 0 || now.y == m-1)
		{
			return dist2[now.x][now.y]; 
		}
		for(int i = 0 ; i < 4 ; i++)
		{
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			int S = dist2[now.x][now.y] + 1;
			if(judge_p(next.x , next.y,S))
			{
				people[next.x][next.y] = 1;
				dist2[next.x][next.y] = dist2[now.x][now.y] + 1;
				People.push(next);
			}
		}
	}
	return -1; 
}

void init()
{
	memset(dist1 , 0 , sizeof(dist1));
	memset(dist2 , 0 , sizeof(dist2));
	memset(people , 0 , sizeof(people));
	memset(fire , 0 , sizeof(fire));
	while(!People.empty())
	{
		People.pop();
	}
	while(!Fire.empty())
	{
		Fire.pop(); 
	}
}
int main()
{
	int t;
	scanf("%d" , &t);

	while(t--)
	{
		node start , second;
		init();
		scanf("%d %d" , &n , &m);
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				cin>>map[i][j];
			}
		}
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				if(map[i][j] == 'J')
				{
				 	start.x = i;
				 	start.y = j;
				}
				if(map[i][j] == 'F')
				{
					fire[x][y] = 1;
					dist1[x][y] = 0;
					now.x = i;
					now.y = j;
					now.step = 0;
					Fire.push(now);
				}
			}
		}
		bfs_fire();
		ans = bfs_people(start.x , start.y);
		if(ans !=-1)
		{
			printf("%d\n" , ans);
		}
		else if(ans == -1)
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
