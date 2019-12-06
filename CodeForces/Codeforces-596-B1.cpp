#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+8;
const int makn = 2e5+10;
int a[makn] , sum = maxn , cnt , color[maxn];
int main()
{
    int t , n , k , d;
    scanf("%d" , &t);
    while(t--)
    {
        memset(color , 0 , sizeof(color));
     //   memset(a , 0 , sizeof(a));
        cnt = 0;
        scanf("%d %d %d" , &n , &k , &d);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &a[i]);
        }
        for(int i = 1 ; i <= d ; i++)
        {
            if(!color[a[i]])
            {
                cnt += 1;
            }
            color[a[i]]++;
        }
        sum = cnt;
        int l = 1 , r = d;
        while(r < n)
        {
            color[a[l]]--;
            if(color[a[l]]==0)
            {
                cnt -= 1;
            } 
            if(color[a[r+1]]==0) 
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
/*
30
4 4 1
3 3 1 2
4 4 1
4 1 4 1
1 1 1
1
3 2 1
2 1 2
4 4 2
3 2 2 2
4 2 4
1 2 2 2
1 4 1
4
2 3 1
2 3
2 2 1
2 2
4 4 2
1 2 4 2
4 4 1
2 4 4 3
4 3 1
1 3 1 3
1 1 1
1
2 2 2
2 1
2 4 1
1 4
2 4 1
3 4
1 2 1
1
2 4 2
2 1
3 1 2
1 1 1
2 4 1
1 4
2 3 1
3 3
4 2 2
2 1 2 2
3 2 2
2 2 1
4 3 1
2 2 1 2
2 3 1
1 3
4 4 4
3 2 2 3
1 4 1
1
2 1 2
1 1
1 4 1
4
2 3 1
3 3
*/
