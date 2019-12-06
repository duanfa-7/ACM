#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 2e5+10;
int a[maxn] , sum[maxn];
int main()
{
    int q , n , k , ans;
    string str1 , str;
    for(int i = 0 ; i <= maxn ; i+=3)
    {
        str1 += "R";
        str1 += 'G';
        str1 += 'B';
    }
    scanf("%d" , &q);
    while(q--)
    {
        ans = INF;
        scanf("%d %d" , &n , &k);
        cin >> str;
        a[0] = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(str1[i] == str[i]) a[i+1] = 0;
            else a[i+1] = 1;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            sum[i] = sum[i-1] + a[i];
        }
        // for(int i = 1 ; i <= n ; i++)
        // {
        //     printf("sum[%d] = %d\n" , i , sum[i]);
        // }
        for(int i = 1 ; i <= (n-k+1) ; i++)
        {
            ans = min(ans , (sum[i+k-1] - sum[i-1]));
        }
        int t1 = ans;
        ans = INF;
        memset(sum , 0 , sizeof(sum));
        memset(a , 0 , sizeof(a));
        for(int i = 0 ; i < n ; i++)
        {
            if(str1[i+1] == str[i]) a[i+1] = 0;
            else a[i+1] = 1;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            sum[i] = sum[i-1] + a[i];
        }
        for(int i = 1 ; i <= (n-k+1) ; i++)
        {
            ans = min(ans , (sum[i+k-1] - sum[i-1]));
        }
        int t2 = ans;
        ans = INF;
        memset(sum , 0 , sizeof(sum));
        memset(a , 0 , sizeof(a));
        for(int i = 0 ; i < n ; i++)
        {
            if(str1[i+2] == str[i]) a[i+1] = 0;
            else a[i+1] = 1;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            sum[i] = sum[i-1] + a[i];
        }
        for(int i = 1 ; i <= (n-k+1) ; i++)
        {
            ans = min(ans , (sum[i+k-1] - sum[i-1]) );
        }
        printf("%d\n" , min(ans , min(t1 , t2)));
    }
    return 0;
}