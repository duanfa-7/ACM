#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+8;
int a[maxn];
int main()
{
    int n;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &a[i]);
    }
    for(int i = 1 ; i < n ; i++)
    {
        printf("%d " , n+1-a[i]);
    }
    printf("%d\n" , n+1-a[n]);
    return 0;
}