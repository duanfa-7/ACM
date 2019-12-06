#include <bits/stdc++.h>
using namespace std;
int dp[10005][30];
int index[30];
int num = 1;

char s1[10005] , s2[1000005];

int main()
{
    while(~scanf("%s %s" , s1 , s2))
    {
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        memset(index , -1 , sizeof(index));
        //index[i] 表示字符s1[i]第一次出现的位置
        memset(dp , -1 , sizeof(dp));
        //dp[i][j]  表示第i个下标后字符j第一次出现的位置
        for(int i = 0 ; i < len1 ; i++)
        {
            if(index[s1[i]-'a'] == -1)
            {
                index[s1[i]-'a'] = i;
            } 
        }
        for(int i = 0 ; i < len1 ; i++)
        {
            for(int j = i+1 ; j < len1 ; j++)
            {
                if(dp[i][s1[j]-'a'] == -1)
                {
                    dp[i][s1[j]-'a'] = j;
                }
            }
        }
        int flag = 0;
        for(int i = 0 ; i < len2 ; i++)
        {
            if(index[s2[i] - 'a'] == -1)
            {
                flag = 1;
                printf("-1\n");
                break;
            }
        }
        if(!flag)
        {
            int pre = index[s2[0] - 'a'];//s2中的第一个字符在s1中的位置
            int next;
            for(int i = 1 ; i < len2 ; i++)
            {
                next = dp[pre][s2[i]-'a'];
                if(next == -1)
                {
                    num++;
                    pre = index[s2[i]-'a'];
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