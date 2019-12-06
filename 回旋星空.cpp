#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
#include <bits/stdc++.h>
struct node
{
    int x;
    int y;
}po[10000]; //    2 
int fun(int x)// A4  即4！/2！//故用到阶乘函数 
{
    if(x == 0 || x == 1)
    {
        return 1;
    }
    return x * fun(x-1);
}
int main()
{
    int T, n ;
        int flag  ;
        int ans ;
    map<double , int> m;
    scanf("%d", &T);
    while(T--)
    {
        double a;
    flag = 0 ;
    ans = 0;
        m.clear();
        scanf("%d" , &n);
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d %d" , &po[i].x, &po[i].y);
        }
     
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(po[i].x != po[j].x || po[i].y != po[j].y)
                {
                     a = sqrt((po[j].y-po[i].y) * (po[j].y-po[i].y) + (po[j].x-po[i].x) * (po[j].x-po[i].x));
                     m[a]++;
                }
            }
            map<double , int >::iterator it;//map的使用 注意 
                for(it = m.begin() ; it != m.end() ; it++)
                {
                    if((*it).second < 2)
                    {
                        continue;
                    }
                    else
                    {
                        flag = 1;
                        ans += fun((*it).second)/fun((*it).second - 2);
                    }
                }
             m.clear();
        }
        if(flag == 0)
        {
            printf("WA\n");
        }
        else
        {
            printf("%d\n" , ans);
         }
         
    }
    return 0;
}
/*
两层for循环将各点到其他点之间的距离存储起来 注意：以一个点开始另一个点结束的时候要将map数组清零， 否则会出现两个距离相等但出现四个点的情况 
4
5
0 1
1 0
0 0
0 2
2 0
*/
