#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T , n , k=1;
    scanf("%d" , &T);
    while(T--)
    {
        scanf("%d" , &n);
        while(n%2 == 0)
        {
            n/= 2;
        }
        while(n%5 == 0)
        {
            n /= 5;
        }
        if(n == 1) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}


//1/n非无限小数要确定n的因子只有 2 或 5