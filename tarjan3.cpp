#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 4e5+8;
vector<int>mp[maxn];
int dfn[maxn] , low[maxn] , vis[maxn] , ans[maxn];
int n , m , cnt , sis , tt;
void init()
{
    memset(dfn , 0 , sizeof(dfn));
    memset(low , 0 , sizeof(low));
    memset(vis , 0 , sizeof(vis));
    for(int i = 1 ; i <= n ; i++) mp[i].clear();
}
void tarjan(int u)
{
    vis[u] = 1;
    dfn[u] = low[u] = cnt++;
    for(int i = 0 ; i < mp[u].size() ; i++)
    {
        int v = mp[u][i];
        if(vis[v]==0)tarjan(v);
        if(vis[v]) low[u] = min(low[u] , low[v]);
    }
    if(dfn[u] == low[u])
    {
        sis++;
    }
}
void solve()
{
    tt = -1 ; cnt = 1;sis=0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(vis[i]==0)tarjan(i);
    }
    printf("sis = %d\n" , sis);
}
int main()
{
    while(~scanf("%d" , &n))
    {
        if(n == 0) break;
        scanf("%d" , &m);
        init();
        for(int i = 1 ; i <= m ; i++)
        {
            int x , y;
            scanf("%d %d" , &x , &y);
            mp[x].push_back(y);
        }
        solve();
    }
    return 0;
}