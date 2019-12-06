#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll solve(ll a , ll b , ll mod)
{
    ll ans;
    while(b)
    {
        if(b%2)
        {
            ans = ((ans%mod) * (a%mod) )%mod;
        }
        a = (a%mod) * (a%mod) % mod;
        b /= 2;
    }
    return ans;
}
int main()
{
    int t , n , m;
    scanf("%d" , &t);
    while(t--)
    {
        scanf("%d %d" , &n , &m);
        ll op = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            op += solve(i , m , mod);
            op = op%mod;
        }
        printf("%lld\n" , op);
    }
    return 0;
}