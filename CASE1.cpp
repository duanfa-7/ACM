#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll b[200000];
int main()
{
    int n , l , p , uu;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++)
    {
        int flag = 0;
        scanf("%d %d" , &p , &l);
            int ans = p-l;
            uu = 0;
            for(int j = 1 ; j <= sqrt(ans) ; j++)
            {
               if(ans%j==0)
                {
                    b[uu++] = j;
                    if(j != ans/j)
                    {
                        b[uu++] = ans/j;
                    } 
                }
            }
            sort(b , b+uu);
            printf("Case %d: " , i);
            for(int j = 0 ; j < uu ; j++)
            {
                if(l < b[j])
                {
                    if(j == uu-1)
                    {
                        printf("%lld" ,b[j]);
                    }
                    else
                    {
                        printf("%lld " ,b[j]);
                    }
                    flag = 1;
                }
            }
            if(flag==0)printf("impossible");
            printf("\n");
    }
    return 0;
}
