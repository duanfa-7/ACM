#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1e6+5;
int n,m,s,t;
ll d[maxn],vis[maxn];
vector<pair<int,ll> >E[maxn];
void spfa()
{
    queue <ll> Q;
    Q.push(s);
    while(!Q.empty())
    {
        ll now = Q.front();
        Q.pop(); vis[now] = 0;    //从队列中弹出now , vis[now] 标记为未访问
        for(int j = 0; j < E[now].size(); j++)
        {
            ll v = E[now][j].first;
            if(d[v] > d[now] + E[now][j].second)
            {
                d[v] = d[now] + E[now][j].second;
                if(vis[v]) continue;    //如果访问过了(也就是 已经在队列中),就不用再push
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
}
void init()
{
    memset(d,inf,sizeof(d));
    memset(vis,0,sizeof(vis));
    for(int i = 0; i <= n; i++) E[i].clear();
}
int main()
{
	int T;
	scanf("%d", &T);
    while(T--)
    {
			scanf("%d%d",&n,&m);
        init();
        int a,b;
				ll x;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%lld",&a, &b, &x);
            E[a].push_back(make_pair(b,x));
        }
				for(int i=0;i<6;i++){
					scanf("%d%d",&t,&s);
					memset(d,inf,sizeof(d));
			    memset(vis,0,sizeof(vis));
					d[s] = 0;
					vis[s] = 1;
					spfa();
					printf("%lld\n", -1 * d[t]);
					E[t].push_back(make_pair(s, -1 * d[t]));
				}
        // d[1] = 0; vis[1] = 1; spfa(); //求坐标1~n的最短路
        // printf("%d\n",d[n]);
    }
    return 0;
}
