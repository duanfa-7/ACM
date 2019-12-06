#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a , b , c;
    int q;
    scanf("%d" , &q);
    while(q--)
    {
        ll ans = 0;
        scanf("%lld %lld %lld" , &a , &b , &c);
        ans  = a+b+c;
        printf("%lld\n" , ans/2);
    }
    return 0;
}