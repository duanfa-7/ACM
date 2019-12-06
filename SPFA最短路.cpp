#include<stdio.h>
#include <iostream>
#include <vector>
#include <queue> 
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1e5+10;
int dis[maxn] , vis[maxn] , ans[maxn] , path[maxn];
int f , n , m , w;
struct node
{
	int to;
	int cost;
	node(int _to , int _cost):to(_to) , cost(_cost){
	}
};
int flag;
vector<node>V[maxn];
int SPFA(int s , int e)
{
	for(int i = 0 ; i <= n+1 ; i++)
	{
		dis[i] = INF;
	}
	dis[s] = 0;
	queue<int>q;
	q.push(s);
	ans[s] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = 0 ; i < V[u].size() ; i++)
		{
			int to = V[u][i].to;
			int w = V[u][i].cost;
			if(dis[to] > dis[u] + w)
			{
				dis[to] = dis[u] + w;
				if(!vis[to])
				{
					vis[to] = 1;
					ans[to]++;
					q.push(to);
					if(ans[to] > e)
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
	int f , n , m, w , u , v , cost , a , b , c;
	cin >> f;
	while(f--)
	{
		int flag = 0;
		for(int i = 0 ; i < n ; i++)V[i].clear();
		cin >> n >> m >> w;
		for(int i = 1 ; i <= m ; i++)
		{
			cin >> u >> v >> cost;
			V[u].push_back(node(v , cost));
			V[v].push_back(node(u , cost));
		}
		for(int i = 1 ; i <= w ;i++)
		{
			cin >> u >> v >> cost;
			V[u].push_back(node(v , cost));
		}
		cout << SPFA(1 , n) << endl;
//		if(SPFA(1 , n))
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
		
	}
	return 0;
}
	

