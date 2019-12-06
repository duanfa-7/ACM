#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
typedef long long LL;
LL gcd(LL x, LL y)
{
    if (!y) return x;
    return (y, x%y);
}
LL pow(LL a, LL x, LL mod)
{
    LL ans = 1;
    while(x)
    {
        if (x & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        x >>= 1;
    }
    return ans;
}
bool MRT(LL x)
{
    if (x == 2) return true;
    for (LL i = 1; i <= 30; ++i)
    {
        LL now = rand()%(x-2) + 2;
        if (pow(now, x-1, x) != 1) return false;
    }
    return true;
}
int main()
{
    int n;
    LL x;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%I64d", &x);
        if (MRT(x)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

