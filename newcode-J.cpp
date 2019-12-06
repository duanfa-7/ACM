#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+8;
char name[maxn];
char s[maxn];
int dp[maxn][30] , Index[maxn];
void init()
{
    int len = strlen(name);
    for(int i = 0 ; i < len ; i++)
    {
        if(Index[name[i]-'a'] == -1)
        {
            Index[name[i]-'a'] = i;
        }
    }
    for(int i = 0 ; i < len ; i++)
    {
        for(int j = i+1 ; j < len ; j++)
        {
            if(dp[i][name[j]-'a'] == -1)
            {
                dp[i][name[j]-'a'] = j;
            }
        }
    }
}
int main()
{
    scanf("%s" , name);
    memset(dp , -1 , sizeof(dp));
    memset(Index , -1 , sizeof(Index));
    init();
    int n;
    scanf("%d" , &n);
    while(n--)
    {    
        scanf("%s" , s);
        int flag = 0;
        int len2 = strlen(s);
        int pre = Index[name[0]-'a'];
        int next;
        if(pre == -1) flag = 1;
        else
        {
            for(int i = 0 ; i < len2 ; i++)
            {
                next = dp[pre][s[i]-'a'];
                if(next == -1)
                {
                    flag = 1;
                    break;
                }
                pre = next;
            }
        }
        if(flag)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}