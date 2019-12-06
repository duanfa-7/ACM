#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
int f[maxn];
void init()
{
    for(int i = 1 ; i <= maxn ; i++)
    {
        f[i] = 0;
    }
}
int main()
{
    init();
    f[0] = 1;
    int n , k , a[maxn];
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &a[i]);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = k ; j >= a[i] ; j--)
        {
            f[j] += f[j-a[i]];
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(f[i] >= k)
        {
            ans++;
        }
    }
    printf("%d\n" , ans);
    return 0;
}