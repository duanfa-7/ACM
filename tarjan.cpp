#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 5e4+8;
int DFN[maxn] , LOW[maxn];
int STACK[maxn] , heads[maxn] , col[maxn] , num[maxn] , visit[maxn];
int oup[maxn] , tot , cnt , INDEX , sis;
int uu[maxn] , vv[maxn];
struct node
{
	int v , next;	
}edge[maxn];
void add(int x , int y)
{
	edge[++cnt].next = heads[x];
	edge[cnt].v = y;
	heads[x] = cnt;
	return;
}
void tarjan(int x)
{
	DFN[x] = LOW[x] = ++tot;
	STACK[++INDEX] = x;
	visit[x] = 1;
	for(int i = heads[x] ; i != -1 ; i = edge[i].next)
	{
		if(!DFN[edge[i].v])
		{
			tarjan(edge[i].v);
			LOW[x] = min(LOW[x] , LOW[edge[i].v]);
		}
		else if(visit[edge[i].v])
		{
			LOW[x] = min(LOW[x] , LOW[edge[i].v]);
		}
	}
	if(DFN[x] == LOW[x])
	{
		sis++;//强连通分量的个数
		do 
		{
			//将一个强连通分量里的各个点标记同样的颜色//缩点
			visit[STACK[INDEX]] = 0;
			col[STACK[INDEX]] = sis;
			num[sis]++;//强连通分量中点的个数 
			INDEX--;
		}while(x != STACK[INDEX+1]); 
	}
	return; 
}
int main()
{
	int n , m ;
	memset(heads , -1 , sizeof(heads));
	memset(oup  , 0 , sizeof(oup));
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; i++)
	{
		scanf("%d %d" , &uu[i] , &vv[i]);
		add(uu[i] , vv[i]);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(!DFN[i]) tarjan(i);
	}
	for(int i = 1 ; i <= m ; i++)
	{
		if(col[uu[i]] != col[vv[i]])
		{
			oup[col[uu[i]]]++;
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= sis ; i++)
	{
		if(oup[i] == 0)
		{
			ans++;
		}
	}
	if(ans >= 2)printf("0\n");
	else
	{
		for(int i = 1 ; i <= sis ; i++)
		{
			if(oup[i] == 0)
			{
				printf("%d\n" , num[i]);
			}
		}
	}
	return 0;
}
/*
6 8
1 3
1 2
2 4
3 4
3 5
4 6
4 1
5 6
*/