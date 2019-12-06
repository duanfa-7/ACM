#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+8;
ll a[maxn] , b[maxn] , w[maxn] , s[maxn];
int main()
{
    ll t , n , m , p ;
    scanf("%lld" , &t);
    while(t--)
    {
        ll sum = 0 , ans = 1e18;
        scanf("%lld %lld %lld" , &n , &m , &p);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%lld" , &s[i]);
        }
        for(int i = 0 ; i < p ; i++)
        {
            scanf("%lld %lld" , &a[i] , &b[i]);
            w[i] = (s[a[i]]-1-(b[i]%m)+m)%m;
            sum += w[i];
        }
        sort(w , w+p);
        for(int i = 0 ; i < p ; i++)
        {
            ans = min( ans , sum+i*m-p*w[i]);
        }
        printf("%lld\n" , ans);
    }
    return 0;
}