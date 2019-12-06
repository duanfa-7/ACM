#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm> 
#include <queue>
#define N 1000000
using namespace std;
struct node 
{
	int x;
	int s;
};
int judge(int x)
{
	if(x >= N || x < 0)return 0;
	return 1; 
}
int n , k;
int vis[N];
queue <node> Q;

int bfs(int n , int k)
{
	node now;
	now.x = n;
	now.s = 0;
	Q.push(now);
	while(!Q.empty())
	{
		node next;
		now = Q.front();
//		cout << "now.x = " << now.x <<"   "<<"now.s = " << k<<endl;
		if(now.x == k)
		{
			return now.s;
		}
		
		Q.pop();
		for(int i = 0 ; i < 3 ; i++)
		{
			if(i == 0)
			{
				next.x = now.x + 1;
				if(judge(next.x) && vis[next.x] == 0)
				{
					vis[next.x] = 1;
					next.s = now.s+1;
					Q.push(next);
				}
			 } 
			
			else if(i == 1)
			{
				next.x = now.x - 1;
				if(judge(next.x)&& vis[next.x] == 0)
				{
					vis[next.x] = 1;
					next.s = now.s+1;
					Q.push(next);
				}
			 } 
			else 
			{
				next.x = now.x * 2;
				if(judge(next.x)&& vis[next.x] == 0)
				{
					vis[next.x] = 1;
					next.s = now.s + 1;
					Q.push(next);
				}
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	memset(vis , 0, sizeof(vis));
	cout << bfs(n , k) << endl;
	return 0;
}
