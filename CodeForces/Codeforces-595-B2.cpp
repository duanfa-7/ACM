#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+8;
int p[maxn] , vis[maxn];
int cnt , num[maxn] , ans[maxn];
int main()
{
    int q , n , t;
    scanf("%d" , &q);
    while(q--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d" , &n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &p[i]);
        }
        for(int i = 1 ; i <= n ; i++)
        {
            cnt = 1;
            if(vis[i]==0)
            {               
                vis[i] = 1;
                int x = p[i];
                t = p[x];
                num[cnt] = x;
                while(x != t)
                {
                    cnt++;
                    num[cnt]=t;
                    vis[t] = 1;           
                    t = p[t];
                }
                for(int j = 0 ; j <= cnt ; j++)
                {
                    ans[num[j]] = cnt;
                }
            }
           
        }
        for(int i = 1 ; i <= n ; i++)
        {
            printf("%d " , ans[i]);
        }
        printf("\n");
    }
    return 0;
}