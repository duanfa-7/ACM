#include <iostream>
#define ll long long
const int mod = 1e7+9;
using namespace std;
ll fastpow(ll a , ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b%2)
        {
            ans *= a%mod;
        }
        a = a*a%mod;
        b/=2;
    }
    return ans%mod;
}
int main()
{
    ll a , b;
    scanf("%lld %lld" , &a , &b);
    printf("%lld" , fastpow(a , b));
    return 0;
}