#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+8;
int a[maxn];
int main()
{
    int n , cnt;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &a[i]);
    }
    sort(a+1 , a+1+n);
    cnt = 0;
    int k = 1;
    for(int i = 1 ; i <= n ; i++)
    {
       if(a[i] >= k)
       {
           cnt++;
           k++;
       }
    }
    printf("%d\n" , cnt);
    return 0;
}