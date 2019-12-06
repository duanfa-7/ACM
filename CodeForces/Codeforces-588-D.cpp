#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4;
map<long long, int>M;
struct node
{
    int a , b;
}num[maxn];
int main()
{
    int n;
    ll ans = 0;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &num[i].a);
        M[num[i].a]++;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &num[i].b);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(M[num[i].a] >= 2) ans += num[i].b;
    }
    printf("%lld\n" , ans);
    return 0;
}