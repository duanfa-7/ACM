#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+8;
int a[maxn] , sum = maxn , cnt , color[maxn];
int main()
{
    int t , n , k , d;
    scanf("%d" , &t);
    for(int p = 1 ; p <= t ; p++)
    {
        memset(color , 0 , sizeof(color));
 //       memset(a , 0 , sizeof(a));
        cnt = 0;
        scanf("%d %d %d" , &n , &k , &d);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &a[i]);
        }
        for(int i = 1 ; i <= d ; i++)
        {
            if(color[a[i]]==0)
            {
                cnt += 1;
            }
            color[a[i]]++;
        }
        sum = cnt;
        int l = 1 , r = d;
        while(r < n)
        {
            if(color[a[l]] == 1)
            {
                cnt -= 1;
            } 
                color[a[l]]--;
            if(color[a[r+1]] == 0) 
            {
                cnt += 1;
            }
           color[a[r+1]]++;
            sum = min(sum , cnt);
            l++;r++;
        }
        printf("%d\n" , sum);
    }
    return 0;
}
