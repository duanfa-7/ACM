#include <stdio.h>
#include <bits/stdc++.h>//将第一组字符串与其倒置后的字符串进行最长公共子序列操作 
#include <iostream>
using namespace std;
int dp[1236][1236];
int main()
{
    string s;
    while(cin >> s)
    {
     
        int n = s.length();
            s = '0' + s; 
        memset(dp , 0 , sizeof(dp));//初始全部为0 
        for(int i = 1 ; i <= n ; i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] -= 32;
            }
        }
        string t = s;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = n ; j  >= 1; j--)
            {
                if(s[i] == t[j])
                {
                    dp[i][j] = dp[i-1][j+1] + 1;
                }
                if(s[i] != t[j])
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j+1]);
                }
            }
        }
        printf("%d\n" , n - dp[n][1]);
    }
 
    return 0;
}
