#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a , b , c , d , k , t;
    int x , y;
    scanf("%d" , &t);
    while(t--)
    {
        scanf("%d%d%d%d%d" , &a , &b , &c , &d , &k);
        x = 0 , y = 0;
        if(a < c) x = 1;
        else if(a%c!=0 ) x=(a/c+1);
        else x = a/c;
        if(b<=d) y=1;
        else if(b%d!=0) y =(b/d+1);
        else y = b/d;
        if((x+y) <= k) printf("%d %d\n" , x , y);
        else printf("-1\n");
    }
    return 0;
}