#include<bits/stdc++.h>
using namespace std;
int edge[50][50];
int main()
{
    int n , m , a , b , ans = 9999;
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; i++)
    {
        scanf("%d %d" , &a , &b);
        edge[a][b] = edge[b][a] = 1;
    }
    if(n<7)printf("%d\n" , m);
    else
    {
        for(int i = 1 ; i <= 7 ; i++)
        {
            for(int j = i+1 ; j <= 7 ; j++)
            {
                int cnt = 0;
                for(int k = 1 ; k <= 7 ; k++)
                {
                    if(edge[i][k] && edge[j][k])
                    {
                        cnt++;
                    }
                }
                ans = min(ans , cnt);
            }
        }
        printf("%d\n" , m-ans);
    }
   
    return 0;
}









//以下为错误代码
/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , m , a , b , minn = 500;
    int inp[50] ;
    memset(inp , 0 , sizeof(inp));
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; i++)
    {
        scanf("%d %d" , &a , &b);
        inp[a]++ ; inp[b]++;
    }
    if(n <= 6) printf("%d\n" , m);
    else
    {
        for(int i = 1 ; i <= n ; i++)
        {
            if(minn>inp[i])
            {
                minn = inp[i];
            } 
        }
        if(m == 0) printf("0\n");
        else printf("%d\n" , m-minn+1);
    }
    return 0;
}*/
/*
7 14
7 3
2 4
2 1
2 5
5 3
6 7
4 7
5 4
7 5
4 3
4 1
6 1
6 3
3 1
*/
