#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+8;
char str1[maxn] , str2[maxn];
int len1 , len2;
int index[30];
int dp[10005][30];
int num = 1;
int main()
{
    while(~scanf("%s %s" , str1 , str2))
    {
        len1 = strlen(str1);
        len2 = strlen(str2);
        memset(index , -1 , sizeof(index));
        //index[i]表示s1字符串中每个字符第一次出现的位置
        memset(dp , -1 , sizeof(dp));
        //dp[i][j] 表示i位置之后str2[j]这个字符第一次出现的位置
        for(int i = 0 ; i < len1 ; i++)
        {
            if(index[str1[i]-'a'] == -1)
            {
                index[str1[i]-'a'] = i;
            }
        }
        for(int i = 0 ; i < len1 ; i++)
        {
            for(int j = i+1 ; j < len1 ; j++)
            {
                if(dp[i][str1[j]-'a'] == -1)
                {
                    dp[i][str1[j]-'a'] = j;
                }
            }
        }
        int flag = 0;
        for(int i = 0 ; i < len2 ; i++)
        {
            if(index[str2[i]-'a'] == -1)
            {
                flag = 1;
                break;
            }
        }
        if(flag) printf("-1\n");
        else
        {
            int pre = index[str2[0]-'a'];
            int next;
            for(int i = 1 ; i < len2 ; i++)
            {
                next = dp[pre][str2[i]-'a'];
                if(next == -1)
                {
                    num++;
                    pre = index[str2[i]-'a'];
                }
                else
                {
                    pre = next;
                }
            }
            printf("%d\n" , num);
        }

    }
    return 0;
} 