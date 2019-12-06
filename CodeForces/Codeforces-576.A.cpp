#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+8;
int a[maxn];
int main()
{
    int n , x , y;
    scanf("%d %d %d" , &n , &x , &y);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &a[i]);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        int flag = 0 , opp = 0;
        for(int j = i-1 ; j >= i -x; j--)
        {
            if(a[j] == 0) break;
            if(a[i] > a[j])
            {
                flag  = 1;
                break;
            }
        }
        for(int j = i+1 ; j <= i+y ; j++)
        {
            if(a[j] == 0) break;
            if(a[i] > a[j])
            {
                opp = 1;
                break;
            }
        }
        if(opp == 0 && flag == 0)
        {
            printf("%d\n" , i);
            break;
        }
    }
    return 0;
}