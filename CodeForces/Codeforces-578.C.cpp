#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n , m , k;
    ll sx , sy , ex , ey;
    scanf("%lld %lld %lld" , &n , &m , &k);
    ll p = (ll) (n/__gcd(n,m) * m);
    ll a = p/n;
    ll b = p/m;
    int flag = 0;
    if(__gcd(n,m) == 1) flag = 1;
    while(k--)
    {
        scanf("%lld %lld %lld %lld" , &sx , &sy , &ex , &ey);
        if(flag == 1) printf("YES\n");
        else
        {
            if(sx == 1 && ex == 2)
            {
                if((sy-1)/b == (ey-1)/a ) printf("YES\n");
                else printf("NO\n");
            }
            else if(sx==2&&ex==1)
            {
                 if((sy-1)/a == (ey-1)/b ) printf("YES\n");
                else printf("NO\n");
            }
            else if(sx == 1 && ex == 1)
            {
                if((sy-1)/b == (ey-1)/b) printf("YES\n");
                else printf("NO\n");
            }
            else if(sx == 2 && ex == 2)
            {
                if((sy-1)/a == (ey-1)/a) printf("YES\n");
                else printf("NO\n");
            }
        }
      
    } 
    return 0;
}
/*
2 3 5
2 3 1 2
2 3 2 3
1 1 1 1
1 2 1 2
2 1 2 1
*/