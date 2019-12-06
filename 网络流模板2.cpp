#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 20;
const int M = 2005;
const int INF = 0x3f3f3f3f;
struct Edge
{
	int to,next,cap,flow;
	Edge ()
	{
		
	};
	Edge (int p_to, int p_next, int p_cap, int p_flow)
	{
		to = p_to;
		next = p_next;
		cap = p_cap;
		flow = p_flow;
	}
}edges[M];
int tol;
int head[N];
int n,m; 
void init()
{
	tol = 2;
	mmset(head,-1);
}
void addEdge(int u,int v,int w,int rw = 0)
{
	edges[tol] = Edge(v,head[u],w,0);
	head[u] = tol++;
	edges[tol] = Edge(u,head[v],rw,0);
	head[v] = tol++;
}
int Q[N],dep[N],cur[N],sta[N];
bool bfs(int s, int t, int n)
{
	int front = 0, tail = 0;
	mmset(dep,-1);
	dep[s] = 0;
	Q[tail++] = s;
	while(front < tail)
	{
		int u = Q[front++];
		for(int i = head[u]; i != -1; i = edges[i].next)
		{
			int v = edges[i].to;
			if(edges[i].cap > edges[i].flow && dep[v] == -1)
			{
				dep[v] = dep[u] + 1;
				if(v == t)
				{
					return true;
				}
				Q[tail++] = v;
			}
		} 
	} 
	return false;
}
int dinic(int s, int t, int n)
{
	int maxflow = 0;
	while(bfs(s,t,n))
	{
		for(int i = 0; i < n; i++)
		{
			cur[i] = head[i];
		}
		int u = s, tail = 0;
		while(cur[s] != -1)
		{
			if(u == t)
			{
				int tp = INF;
				for(int i = tail - 1; i >= 0;i--)
				{
					tp = min(tp,edges[sta[i]].cap - edges[sta[i]].flow);
				}
				maxflow += tp;
				for(int i = tail - 1; i >= 0; i--)
				{
					edges[sta[i]].flow += tp;
					edges[sta[i] ^ 1].flow -= tp;
					if(edges[sta[i]].cap - edges[sta[i]].flow == 0)
					{
						tail = i;
					}
				}
				u = edges[sta[tail] ^ 1].to;
			}
			else if(cur[u] != -1 && edges[cur[u]].cap > edges[cur[u]].flow && dep[u] + 1 == dep[edges[cur[u]].to])
			{
				sta[tail++] = cur[u];
				u = edges[cur[u]].to;
			}
			else 
			{
				while(u != s && cur[u] == -1)
				{
					u = edges[sta[--tail] ^ 1].to;
				}
				cur[u] = edges[cur[u]].next;
			}
		} 
	}
	return maxflow;
}

/*
2
3 2
1 2 1
2 3 1
3 3
1 2 1
2 3 1
1 3 1

Case 1: 1
Case 2: 2

15
4 4
2 3 20
3 2 10
1 2 15
4 3 20
*/ 
int main()
{
	int T;
	scanf("%d",&T);
	int num = 1;
	while(T--)
	{
		init();
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= m; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
		}
		
		int res = dinic(1,n,n);
		printf("Case %d: %d\n",num++,res);
		
	}
	return 0;
} 

