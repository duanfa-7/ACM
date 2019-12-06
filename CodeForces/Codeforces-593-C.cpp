#include <bits/stdc++.h>
using namespace std;
int Map[400][400];
void init(int n)
{
    int cnt = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            Map[i][j] = cnt++;
        }
    }
}
int main()
{
    int n;
    scanf("%d" , &n);
    init(n);
    if(n%2 == 0)
    {
         for(int i = 1 ; i <= n ; i++)
        {
            int cnt = 1;
            while(cnt <= n/2)
            {
                printf("%d %d ",Map[cnt][i] , Map[n-cnt+1][n-i+1]);
                cnt++;
            }
            printf("\n");
        }
    }
     else
     {
        for(int i = 1 ; i <= n ; i++)
        {
            int cnt = 1;
            while(cnt <= n/2)
            {
                printf("%d %d ",Map[cnt][i] , Map[n-cnt+1][n-i+1]);
                cnt++;
                if(cnt == (n/2+1)) printf("%d" , Map[cnt][i]);
            }
            printf("\n");
        }
     }
    return 0;
}