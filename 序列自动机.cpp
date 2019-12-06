#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+20;
char name[maxn];
char s[maxn];
int dp[maxn][30] ;
void init()
{
    int len = strlen(name+1);
    for(int i = len ; i >= 1 ; i--)
    {
        for(int j = 0 ; j < 26 ; j++)
        {
           dp[i-1][j] = dp[i][j];
        }
        dp[i-1][name[i]-'a'] = i;
    }
}
int main()
{
    scanf("%s" , name+1);
    memset(dp , -1 , sizeof(dp));
    init();
    int n;
    scanf("%d" , &n);
    while(n--)
    {    
        scanf("%s" , s);
        int flag = 0;
        int len2 = strlen(s);
        int pre = 0;
        for(int i = 0 ; i < len2 ; i++)
        {
            pre = dp[pre][s[i]-'a'];
            if(pre == -1)
            {
                flag = 1;
                break;
            }
        }
        if(flag)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}