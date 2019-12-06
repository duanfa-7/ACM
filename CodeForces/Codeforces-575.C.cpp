#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+8;
int x[maxn] , y[maxn];
int f1 , f2 , f3 , f4;
int maxx , minx , maxy , miny;
int main()
{
    int q , n ;
    scanf("%d" , &q);
    while(q--)
    {
        maxy = maxx = 100000;miny = minx = -100000;
        scanf("%d" , &n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d %d %d %d %d %d" , &x[i] , &y[i] , &f1 , &f2 , &f3 , &f4);
            if(f1 == 0) minx = max(minx , x[i]);
            if(f2 == 0) maxy = min(maxy , y[i]);
            if(f3 == 0) maxx = min(maxx , x[i]);
            if(f4 == 0) miny = max(miny , y[i]);
        }
        if((minx > maxx ) || (miny > maxy))
        {
            printf("0\n");
        }
        else
        {
            printf("1 %d %d\n" , maxx , maxy);
        }
    }
    return 0;
}