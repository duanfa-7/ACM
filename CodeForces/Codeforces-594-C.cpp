#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e5+8;
int dp[maxn];
int main()
{
    int n , m;
    dp[1] = 2;
    dp[2] = 4;
    scanf("%d %d" , &n , &m);
    for(int i = 3 ; i <= maxn ; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
        dp[i] %= mod;
    }
    printf("%d\n" ,(dp[n]+dp[m]-2) %mod);
    return 0;
}