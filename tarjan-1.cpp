#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4+8;
int DFN[maxn] , LOW[maxn];
int STACK[maxn] , heads[maxn] , col[maxn] , num[maxn] , visit[maxn];
int oup[maxn] , tot  , cnt , INDEX , sis;
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
            LOW[x] = min(LOW[x] , LOW[edge[i].v]);
        //比较谁是谁的儿子/父亲
        }
    }
    if(DFN[x] == LOW[x])//发现是整个强连通分量子树里的最小根
    {
        sis++;
        do
        {
            visit[STACK[INDEX]] = 0;
            col[STACK[INDEX]] = sis;
            num[sis]++;
            INDEX--;
        }while(x != STACK[INDEX+1]);//出栈并且输出
        printf("\n");
    }
    return;
}
int main()
{
    int n , m;
    memset(heads , -1 , sizeof(heads));
    memset(oup , 0 , sizeof(oup));
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
    if(ans >= 2) printf("0\n");
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