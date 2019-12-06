#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q , n , a;
    scanf("%d" , &q);
    while(q--)
    {
        int ans = 0;
        scanf("%d" , &n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &a);
            ans += a;
        }
        if(ans%n!=0)printf("%d\n" , ans/n+1);
        else printf("%d\n" , ans/n);
    }
    return 0;
}