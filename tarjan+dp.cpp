#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1e5;
int DFN[maxn] , LOW[maxn];
int STACK[maxn] , heads[maxn] , col[maxn] , visit[maxn];
int cnt , tot , INDEX , opp;
int sis , num[maxn] , numnew[maxn];//点权值 
int uu[maxn] , vv[maxn] , in[maxn];  //边 
int dp[maxn];//求最大权值 
struct node
{
	int v , next;
}edge[maxn];
vector<int>G[maxn];//新图
vector<int>ans;//拓扑序 
queue<int>Q;
void add(int x , int y)
{
	edge[++cnt].next = heads[x];
	edge[cnt].v = y;
	heads[x] = cnt;
	return;
}
void tarjan(int x)
{
	DFN[x] = LOW[x] = ++tot;//新进点的初始化
	STACK[++INDEX] = x;//x这个点入栈
	visit[x] = 1;//标记x已经在栈里
	for(int i = heads[x] ; i != -1 ; i = edge[i].next)
	{
		if(!DFN[edge[i].v])//如果没有访问过
		{
			tarjan(edge[i].v);//往下进行延伸，开始递归
			LOW[x] = min(LOW[x] , LOW[edge[i].v]);
			//递归出来比较谁是最小根
		}
		else if(visit[edge[i].v])//如果该点访问过并且已经在栈内
		{
			LOW[x] = min(LOW[x] , DFN[edge[i].v]);
			 //比较谁是谁的儿子/父亲
		}
	 } 
	 if(LOW[x] == DFN[x])//发现是整个强连通分量子树里的最小根
	 {
	 	sis++;
	 	do
		{
		//	printf("lalallalal = %d " , STACK[INDEX]);
			col[STACK[INDEX]] = sis;
			visit[STACK[INDEX]] = 0;
			numnew[sis] += num[STACK[INDEX]];//缩点后新的点权值 
		 	INDEX--;
		} while(x != STACK[INDEX+1]); //出栈并且输出
	 }
	 return;
}
void tuopu()
{
	for(int i = 1 ; i <= sis ; i ++)
	{
		dp[i] = numnew[i];
	}
	while(!Q.empty())
	{
		int p = Q.front();Q.pop();
		ans.push_back(p);
		for(int i = 0 ; i < G[p].size() ; i++)
		{
			int y = G[p][i];
			dp[y] = max(dp[y] , dp[p] + numnew[y]);
			in[y]--;
			if(in[y] == 0)
			{
				Q.push(y);
			}
		}
	} 
}
int main() 
{
	int n , m;
	opp = 0;
	memset(heads , -1 , sizeof(heads));
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; i++)
	{
	 	int op;
	 	scanf("%d" , &op);
		num[i] = op; //该点的点权值 
	}
	for(int i = 1 ; i <= m ; i++)
	{
		scanf("%d %d" , &uu[i] , &vv[i]);
		add(uu[i] , vv[i]);
	 } 
	 
	 for(int i = 1 ; i <= n ; i++)
	 {
	 	if(!DFN[i]) tarjan(i);
	 }
	int flag = 0;
	 for(int i = 1 ; i <= m ; i++)//建成新图 
	 {
	 	if(col[uu[i]] != col[vv[i]])
	 	{
	 		flag =1;
	 		G[col[uu[i]]].push_back(col[vv[i]]);
	 		in[col[vv[i]]]++;
		}
		if(i == m && flag == 0)
		{
			opp = numnew[col[uu[i]]];
		}
	 }
	for(int i = 1 ; i <= sis ; i++)
	{
		if(!in[i]) Q.push(i);
	}
	tuopu();
	for(int i = 1 ; i <= sis ; i++)
	{
		opp = max(opp , dp[i]); 
	}
		printf("%d\n" , opp);

	return 0;
 } 
 /*
 5 5
 1 1 1 1 1
 2 1
 3 1
 3 2
 2 4
 4 5
 6 8
 1 1 1 1 1 1
 1 2
 2 3
 3 6
 1 4 
 4 5 
 5 6
 2 5
 5 1
 
10 20
970 369 910 889 470 106 658 659 916 964 
3 2
3 6
3 4
9 5
8 3
5 8
9 1
9 7
9 8
7 5
3 7
7 8
1 7
10 2
1 10
4 8
2 6
3 1
3 5
8 5
 */
