#include <bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
    int q , n;
    scanf("%d" , &q);
    while(q--)
    {
        int flag = 0;
        scanf("%d" , &n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &a[i]);
        }
        sort(a+1 , a+1+n);
        for(int i = 1 ; i < n ; i++)
        {
            if(a[i+1]-a[i] == 1)
            {
                flag = 1;
                break;
            }
        }
        if(flag) printf("2\n");
        else printf("1\n");
    }

    return 0;
}