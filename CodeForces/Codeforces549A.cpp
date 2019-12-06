#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+8;
int a[maxn] , vis[maxn];
int main()
{
    int t;
    scanf("%d" , &t);
    for(int i = 1 ; i <= t ; i++)
    {
        scanf("%d" , &a[i]);
        vis[a[i]]++;
    }
    for(int i = 1 ; i <= t ; i++)
    {
        vis[a[i]]--;
        if(vis[a[i]] == 0)
        {
            printf("%d\n" , i);
            break;
        }
    }
    return 0;
}