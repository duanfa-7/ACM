#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
    int t;
    int x , a , y , b;
    scanf("%d" , &t);
    while(t--)
    {
        scanf("%d %d %d %d" , &x , &a , &y , &b);
        while(1)
        {
            if(x == 1 && y == 1)
            {
                printf("Yes\n");
                break;
            }
            if(x < y && a < b || x > y && a > b)
            {
                printf("No\n");
                break;
            }
            if(x == y && a != b || x != y && a == b)
            {
                printf("No\n");
                break;
            }
            if(x < y && a > b)
            {
                if(y % x != 0)
                {
                    printf("No\n");
                    break;
                }
                else
                {
                    y = y / x;
                    a = a - b;
                }
            }
                if(x < y && a < b || x > y && a > b)
            {
                printf("No\n");
                break;
            }
            if(x == y && a != b || x != y && a == b)
            {
                printf("No\n");
                break;
            }
              if( x > y && a < b)
            {
                if(x % y != 0)
                {
                    printf("No\n");
                    break;
                }
                else
                {
                    x = x / y;
                    b = b - a;
                }
            }
            if(x == y && a == b)
            {
                printf("Yes\n");
                break;
            }
 
        }
    }
 
    /*
    简单的整除化简
	 
    4
    2 20 4 10
    20 20 20 20
    20 21 21 20
    32768 32768 1048576 24576
    */
    return 0;
}
