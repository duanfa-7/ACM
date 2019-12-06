#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n , m , q;
    int sx , sy , ex , ey;
    scanf("%d %d %d" , &n , &m ,&q);
    int nei = n/__gcd(n , m);
    int wai = m/__gcd(n , m);
    while(q--)
    {
        scanf("%d %d %d %d" , &sx , &sy , &ex , &ey);
        if(sy%nei < nei && ey%wai < wai)
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}