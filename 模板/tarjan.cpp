#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int visit[maxn] , DFN[maxn] , LOW[maxn] ;
int stack[maxn] , heads[maxn] , cnt , index , tot;
struct node
{
    int v , next;
}edge[maxn];
vois add(int x , int y)
{
    edge[++cnt].next = heads[x];
    edge[cnt].v = y;
    heads[x] = cnt;
    return ;
}
void tarjan(int x)
{
    DFN[x] = LOW[x] = ++tot;//新进点初始化
    stack[++index] = x;
    visit[x] = 1;
    for(int i = heads[x] ; i != -1 ; i = edge[x].next)
    {
        if(!DFN[edge[i].v])
        {
            tarjan(edge[i].v);
            LOW[x] = min(LOW[x] , LOW[edge[i].v]);//不太懂这里有什么意义
        }
        else if(visit[edge[i].v])
        {
            LOW[x] = min(LOW[x] , DFN[edge[i].v]);
        }
    }
    if(LOW[x] == DFN[x])
    {
        do
        {
            printf("%d " , stack[index]);
            visit[stack[index]] = 0;
            index--;
        }while(x != stack[index+1]);
        printf("\n");
    }
return;
}
int main()
{
    memset(heads , -1 , sizeof(heads));
    int n , m;
    scanf("%d %d" , &n , &m);
    int x , y;
    for(int i = 1 ; i <= m ; i++)
    {
        scanf("%d %d" , &x , &y);
        add(x , y);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(!DFN[i]) tarjan(i);
    }
    return 0;
}