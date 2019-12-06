#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int maxn = 3e3+8;
struct node 
{
	ll num;
	ll cost;
}a[maxn];
ll dis[maxn][maxn];
ll dp[maxn][2];
int n;
void init()
{
	for(int i = 1 ; i <= n ; i++)
	{
		ll t = 0;
		for(int j = i+1 ; j <= n ; j++)
		{
			t += (a[j].num-a[i].num);
			dis[j][i] = t;
		}
	}
}
int cmp(node a , node b)
{
	return a.num < b.num;
}
int main()
{
	while(~scanf("%d" , &n))
	{
		memset(dp , INF , sizeof(dp));
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%lld %lld" , &a[i].num , &a[i].cost);
		}
		sort(a+1 , a+1+n , cmp);
		init();
		dp[1][1] = a[1].cost;
		for(int i = 2 ; i <= n ; i++)
		{
			dp[i][1] = min(dp[i-1][1] , dp[i-1][0]) + a[i].cost;
			for(int j = 1 ; j < i ; j++)
			{
				dp[i][0] = min(dp[i][0] , dp[j][1] +dis[i][j]);
			}
		}
		ll ans = min(dp[n][1] , dp[n][0]);
		printf("%lld\n" , ans);
	}

	
	return 0;
} 