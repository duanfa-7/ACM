#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6+8;
int fat[maxn] , tot;
void find_fat(int val)
{
    tot = 0;
    for(int i = 1 ; i*i <= val ; i++)
    {
        if(val%i==0)
        {
            fat[++tot] = i;
            if(val/i != i)
            {
                fat[++tot] = val/i;
            } 
        }
    }
}
int main()
{
    int a , b , n ,low , heigh;
    scanf("%d %d" , &a , &b);
    int ans = __gcd(a , b);
    find_fat(ans);
    fat[++tot] = ans;
    sort(fat+1 , fat+tot+1);
    scanf("%d" , &n);
    while(n--)
    {
        scanf("%d %d" , &low , &heigh);
        int cnt = upper_bound(fat+1, fat+tot+1, heigh)-fat-1;
        if(fat[cnt] < low) printf("-1\n");
        else printf("%d\n" , fat[cnt]);
    }
    return 0;
}