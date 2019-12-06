#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+8;
ll a[maxn];
int main()
{
    int n ;
    ll ans = 0;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%lld" , &a[i]);
        ans += a[i];
    }
    sort(a+1 , a+1+n);
    if(ans%2==0 && (ans-a[n] >= a[n]) )printf("YES\n");
    else printf("NO\n");
    return 0;
}