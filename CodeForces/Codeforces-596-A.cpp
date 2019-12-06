#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a , b;
    scanf("%d %d" , &a , &b);
    if(a==b)
    {
        printf("%d %d\n",a*10 , a*10+1);
    }
    else if(a == b-1)
    {
        printf("%d %d\n" , a*10+9 , b*10);
    }
    else if(a == 9 && b == 1)
    {
        printf("9 10\n");
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}