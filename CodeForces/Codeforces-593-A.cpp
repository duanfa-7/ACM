#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t , a , b , c;
    int ans ;
    scanf("%d" , &t);
    while(t--)
    {
        ans = 0;
        scanf("%d %d %d" ,&a , &b , &c);
        while(c >= 2 && b >= 1)
        {
            c-=2;
            b-=1;
            ans+=3;
        }
        while(b>=2&&a>=1)
        {
            b-=2;
            a-=1;
            ans+=3;
        }
        printf("%d\n" , ans);
    }
    return 0;
}