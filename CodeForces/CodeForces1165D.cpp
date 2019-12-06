#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6+8;
int vis[maxn];
int main()
{
    int t , n , a[500] ;
    scanf("%d" , &t);
    while(t--)
    {
        memset(vis , 0 , sizeof(vis));
        scanf("%d" , &n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &a[i]);
            vis[a[i]] = 1;
        }
        ll ans = a[1];
        for(int i = 2 ; i <= n ; i++)
        {
            if(ans % a[i] != 0)
            {
                ll op = max(ans , (ll)a[i]);
                ans = __gcd(ans , (ll)a[i]) * op;
            }
        }
        if(vis[ans])printf("%lld\n" , ans*2);
        else printf("%lld\n" , ans);
    }
    return 0;
}