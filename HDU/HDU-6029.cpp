#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+8;
int a[maxn];
int main()
{
    int t , n;
    scanf("%d" , &t);
    while(t--)
    {
        int flag = 0;
        scanf("%d" , &n);
        if(n%2)flag =1;
        a[1] = 2;
        for(int i = 2 ; i <= n ; i++)
        {
            scanf("%d" , &a[i]);
        }
        int cnt = 0 , cnt1 = 0;
        for(int i = n ; i > 0 ; i--)
        {
            if(a[i] == 1)
            {
                cnt++;
            }
            if(a[i] == 2)
            {
                cnt1++;
            }
            if(cnt < cnt1)
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