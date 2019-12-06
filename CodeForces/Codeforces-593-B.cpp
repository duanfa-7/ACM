#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
/*
每一个礼物都是互不影响的 ， 因此对于每一个礼物而言 ， 这个箱子是放或不放。不能有全部为空箱，因此减一
*/
int qpow(ll a , ll b )
{
    ll ans = 1;
    while(b)
    {
        if(b%2==1) ans = (ans%mod)*(a%mod) %mod; 
        a = (a%mod)*(a%mod)%mod;
        b/=2;
    }
    return ans;
}
int main()
{
    ll n , m;
    scanf("%lld %lld" , &n , &m);
    ll cont = qpow(2,m);
    ll cnt = qpow(cont-1,n);
    printf("%lld\n" , cnt);
    return 0;
}