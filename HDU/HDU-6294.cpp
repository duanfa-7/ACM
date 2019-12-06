#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+8;
int dp[maxn];
int main()
{
    int t , n;
    char str[maxn];
    scanf("%d" , &t);
    while(t--)
    {
        memset(dp , -1 , sizeof(dp));
        scanf("%d" , &n);
        scanf("%s" , &str);
        if(str[n-1] <= str[n-2])dp[n-1] = 0;
        else dp[n-1] = 1;
        for(int i = n-2 ; i > 0 ; i--)
        {
            if(str[i] > str[i-1])
            {
                dp[i] = 1; 
            }
            else if(str[i] < str[i-1])
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i+1];
            }
        }
        for(int i = 1 ; i < n ; i++)
        {
         //   printf("%d " , dp[i]);
            if(dp[i] == 0)
            printf(">");
            if(dp[i] == 1)
            printf("<");
        }
        printf("\n");
    }
    return 0;
}