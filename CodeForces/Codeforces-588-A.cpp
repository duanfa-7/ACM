#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[8];
    for(int i = 0 ; i < 4 ; i++)
    {
        scanf("%d" , &a[i]);
    }
    sort(a , a+4);
    if((a[0]+a[3]) == (a[1]+a[2]) || (a[0]+a[1]+a[2] == a[3])) printf("YES\n");
    else printf("NO\n");
    return 0;
}