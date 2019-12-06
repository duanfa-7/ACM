#include <stdio.h>
#include <queue>
#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 220;
char Map[maxn][maxn];
int vis[maxn][maxn];
int ans ;
int person1[maxn][maxn],person2[maxn][maxn];
int n , m;
struct node
{
	int x, y , step;
	node(int x , int y , int step) : x(x) , y(y) , step(step){}
};
int dir[4][2] = {0 , 1 , 1 , 0 , 0 , -1 , -1 , 0};
queue<node> P1 , P2;
bool judge(int x , int y)
{
	if(Map[x][y] == '#' || x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1)return false;
	return true;
}
void bfs_1(int x , int y , int step)
{
	memset(vis , 0 , sizeof(vis));
	vis[x][y] = 1;
	P1.push(node(x , y , 0));
	while(!P1.empty())
	{
		node u = P1.front();
		if(Map[u.x][u.y] == '@')
		{
			person1[u.x][u.y] = u.step;
		}
		P1.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			
			int xx = u.x + dir[i][0];
			int yy = u.y + dir[i][1];
			int ss = u.step + 1;
			if(judge(xx , yy))
			{
				vis[xx][yy] = 1;
				person1[xx][yy] = ss;
				P1.push(node(xx,yy,ss));
			}
		 } 
	}
}
void bfs_2(int x , int y , int s)
{
	memset(vis , 0 , sizeof(vis));
	P2.push(node(x , y , 0));
	vis[x][y] = 1;
	while(!P2.empty())
	{
	node u = P2.front();
		P2.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			int dx = u.x + dir[i][0];
			int dy = u.y + dir[i][1];
			int ds = u.step + 1;
			if(judge(dx , dy))
			{
				vis[dx][dy] = 1;
				person2[dx][dy] = ds;
				P2.push(node(dx , dy , ds));
				if(Map[dx][dy] == '@')
				{
					ans = min(ans , 11*(person1[dx][dy] + person2[dx][dy]));
				}
			}
		}
	}
}
int main()
{
	while(~scanf("%d %d" , &n , &m))
	{
		int sx , sy , ex , ey;
		for(int i = 0 ; i < n ; i++) scanf("%s" , Map[i]);
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				if(Map[i][j] == 'Y')
				{
					sx = i; sy = j;
					person1[i][j] = 0;
				}
				if(Map[i][j] == 'M')
				{
					ex = i; ey = j;
					person2[i][j] = 0;
				}
			}
		}
		ans = 9999999;
		bfs_1(sx , sy , 0);
		bfs_2(ex , ey , 0);
		cout << ans << endl;
	}
	return 0;
 } 
