#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+8;
int a[maxn];
int main()
{
    int n , b = 0 , c = 0, d;
    scanf("%d" , &n);
    int mid = 1e6/2;
    int flag = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &a[i]);
        if(a[i] <= mid)
        {
            b = a[i];
        }
        if(a[i] > mid && flag == 0)
        {
            c = a[i];
            flag = 1;
        }
    }
    if(b == 0 && c!= 0)
    {
        printf("%d\n" , 1e6-c);
    }
    else if (b!=0 && c==0)
    {
        printf("%d\n" , b);
    }
    else if (b!=0 && c!=0)
    {
        int ans = max(b , 1e6-c);
        printf("%d\n" , ans);
    }

    return 0;
}