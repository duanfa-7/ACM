#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 2e5+10;
int a[maxn] , sum[maxn];
int main()
{
    int q , n , k , ans;
    string str1 , str;
    for(int i = 1 ; i <= maxn ; i+=3)
    {
        str1 += "R";
        str1 += "G";
        str1 += "B";
    }
    scanf("%d" , &q);
    while(q--)
    {
        ans = INF;
        scanf("%d %d" , &n , &k);
        cin >> str;
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(str1[i+j] == str[j]) a[j+1] = 0;
                else a[j+1] = 1;
            }
            for(int j = 1 ; j <= n ;j++)
            {
                sum[j] = sum[j-1] + a[j];
            }
            for(int j = 1 ; j <= (n-k+1) ; j++)
            {
                ans = min(ans , (sum[j+k-1] - sum[j-1]));
            }
        }
        printf("%d\n" , ans);
    }
    return 0;
}