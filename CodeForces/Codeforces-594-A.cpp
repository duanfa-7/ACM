#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t , n , m , p , q ;
    ll nji , nou , mji , mou;
    scanf("%lld" , &t);
    while(t--)
    {
         nji = 0 ; nou = 0; mji = 0; mou = 0;
        scanf("%lld" , &n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%lld" , &p);
            if(p%2==0 || p==0)nou++;
            else nji++;
        }
        scanf("%lld" , &m);
        for(int i = 1 ; i <= m ; i++)
        {
            scanf("%lld" , &q);
            if(q%2==0||q==0)mou++;
            else mji++;
        }
        ll ans = (nji*mji)+(nou*mou);
        printf("%lld\n" , ans);
    }
    return 0;
}