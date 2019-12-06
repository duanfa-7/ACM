#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 3e5+80;
int a[maxn<<1] , b[maxn] , Max[maxn];
int main()
{
    int n ;
    while(~scanf("%d" , &n))
    {
        memset(Max , 0 , sizeof(Max));
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &a[i]);
            a[i] = a[i]-i;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &b[i]);
        }
         priority_queue<int>Q;
        for(int i = n ; i >= 1 ; i--)
        {
            Max[i] = max( a[i] , Max[i+1]);
        }
        sort(b+1 , b+1+n);
        for(int i = 1 ; i <= n ; i++)
        {
            Q.push(Max[b[i]]);
        }
        int tmp = 0 , sum = 0;
        for(int i = n+1 ; i <= 2*n ; i++)
        {
            int s = Q.top();
            if(tmp > s)
            {
                a[i] = tmp-i;
            }
            else
            {
                a[i] = s - i;
                Q.pop();
            }
            sum = (sum%mod+a[i]%mod+i)% mod;
            tmp = max(tmp , a[i]);
        }
       printf("%d\n" , sum%mod);
    }
    return 0;
}