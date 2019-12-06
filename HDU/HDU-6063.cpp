#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9+7;
ll solve(ll a , ll b)
{
    ll ans = 0;
    while(b)
    {
        if(b%2==1)
        {
            ans *= a % mod;
        }
        a = (a%mod)*(a%mod) % mod ;
        b/=2;
    }
    return ans;
}
int main()
{
    ll n , k;
    ll num = 1;
    while(~scanf("%lld %lld" , &n , &k))
    {
        printf("Case #%lld: %lld\n" , num++ , solve(n , k));
    }
    return 0;
}