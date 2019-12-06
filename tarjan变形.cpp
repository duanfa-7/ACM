#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int maxn = 5e4+8;
int DFN[maxn] , LOW[maxn];
int STACK[maxn] , heads[maxn] , col[maxn] , num[maxn] , visit[maxn];
int inp[maxn] , tot , cnt , INDEX , sis , minm[maxn] , money[maxn];
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
		sis++;
		do 
		{
			visit[STACK[INDEX]] = 0;
			col[STACK[INDEX]] = sis;
         // if(m oney[STACK[INDEX]] != 0) num[sis] = 1;
			minm[sis] = min(minm[sis] , money[STACK[INDEX]]);//维护最小值
			INDEX--;
		}while(x != STACK[INDEX+1]); 
	}
	return; 
}
int main()
{
	int n , m , p , x ,y;
	memset(heads , -1 , sizeof(heads));
    memset(minm , INF , sizeof(minm));
    memset(money , INF , sizeof(money));
	scanf("%d %d" , &n , &p);
	for(int i = 1 ; i <= p ; i++)
    {
        scanf("%d %d" , &x , &y);
        money[x] = y;
    }
    scanf("%d" , &m);
    for(int i = 1 ; i <= m ; i++)
    {
        scanf("%d %d" , &uu[i] , &vv[i]);
        add(uu[i] , vv[i]);
    }
	for(int i = 1 ; i <= n ; i++)
	{
		if(!DFN[i] && money[i] != INF) tarjan(i);
	}
	for(int i = 1 ; i <= m ; i++)
	{
		if(col[uu[i]] != col[vv[i]])
		{
			inp[col[vv[i]]]++;
		}
	}
    int ans = 0;
    int flag = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!col[i])
        {
            flag = 1;
            printf("NO\n");
            printf("%d\n" , i);
            break;
        }
    }
	if(flag == 0)
    {
        for(int i = 1 ; i <= sis ; i++)
        {
            if(inp[i] == 0)
            {  
                ans += minm[i];
            }
        }
            printf("YES\n");
            printf("%d\n" , ans);
    }
	

	
	return 0;
}