#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn] ;
int main()
{
    int q , n , k , num;
    scanf("%d" , &q);
    while(q--)
    {
        num = 0;
        scanf("%d %d" , &n , &k);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &a[i]);
            if(a[i]%2) num++;
        }
        if(num < k) printf("NO\n");
        else
        {
            if((num-(k-1)) % 2)
            {
                printf("YES\n");
               
                int cnt = 0;
                for(int i = 1 ; i <= n-1 ; i++)
                {
                    if(cnt == k-1) break;
                    if(a[i] %2) 
                    {
                        printf("%d " ,i);
                        cnt++;
                    }
                } 
                printf("%d\n" , n);
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}