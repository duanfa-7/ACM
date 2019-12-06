#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t , n , m , k , a[200] , flag;
    scanf("%d" , &t);
    while(t--)
    {
        flag = 0;
        scanf("%d %d %d" , &n , &m , &k);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &a[i]);
        }
        for(int i = 1 ; i < n ; i++)
        {
            if(a[i] > a[i+1])
            {
                if(a[i+1] >= k)
                {
                    m += (a[i]-(a[i+1]-k));
                }
                else
                {
                    m += a[i];
                }
            }
            else
            {
                if(k < a[i+1])
                {
                    if(a[i]+m >= a[i+1]-k)
                    {
                        m -= (a[i+1]-k-a[i]);
                    }
                    else
                    {
                        flag =1;
                    }
                }
                else
                {
                    m += a[i];
                }
            }
        }
         if(flag) printf("NO\n");
         else printf("YES\n");
    }
    return 0;
}
/*
20
3 0 0
1000000 0 1000000
3 0 0
999999 0 1000000
3 0 1
999999 0 1000000
3 1 0
999999 0 1000000
3 0 500000
0 500000 1000000
3 0 1

1 1 4
4 0 1
1 1 1 4
5 0 1
1 1 1 1 4


YES
NO
YES
YES
YES

*/