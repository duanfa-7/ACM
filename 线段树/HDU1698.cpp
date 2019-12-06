#include <bits/stdc++.h>
#define lson l ,  m , rt<<1
#define rson m+1 , r , rt<<1|1
using namespace std;
const int maxn = 1e5+8;
int sum[maxn<<2];
int lazy[maxn<<2];
void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void Build(int l , int r , int rt)
{
    lazy[rt] = 0;
    sum[rt] = 1;
    if(l == r)
    {
        return;
    }
    int m = (l+r) >> 1;
    Build(lson);
    Build(rson);
    PushUp(rt);
}
void PushDown(int rt , int m)
{
    if(lazy[rt])
    {
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        sum[rt<<1] = (m-(m>>1)) * lazy[rt];
        sum[rt<<1|1] = (m>>1) * lazy[rt];
        lazy[rt] = 0;
    }
}
void Update(int p , int add , int l , int r , int rt)//单点增减
{
    if(l == r)
    {
        sum[rt] += add;
        return;
    }
    int m = (r+l)>>1;
    if(p <= m) Update(p , add , lson);
    else Update(p , add , rson);
    PushUp(rt);
}
int query(int L , int R , int l , int r , int rt)//区间求和
{
    if(L <= l && r <= R)
    {
        return sum[rt];
    }
    int m = (l+r) >> 1;
    int ret = 0;
    if(L <= m) ret += query(L , R , lson);
    if(R > m) ret += query(L , R , rson);
    return ret;
}
void QueryChange(int L , int R , int sc , int l , int r , int rt)
{
    if(L <= l && r <= R)
    {
        lazy[rt] = sc;
        sum[rt] = sc * (r-l+1);;
        return;
    }
    PushDown(rt , r-l+1);
    int m = (l + r) >> 1;
    if(L <= m) QueryChange(L , R , sc , lson);
    if(R > m)  QueryChange(L , R , sc , rson);
    PushUp(rt);
}
int main()
{
    int t , n , m ,  x , y , z;
    scanf("%d" , &t);
    for(int i = 1 ; i <= t ; i++)
    {
        scanf("%d%d" , &n , &m);
        Build(1 , n , 1);
        while(m--)
        {
            scanf("%d %d %d" , &x , &y , &z);
            QueryChange(x , y , z , 1 , n , 1);
        }
        printf("Case %d: The total value of the hook is %d.\n" , i , sum[1]);
    }
    
    return 0;
}
/*
1
10 2
1 5 2
5 9 3
*/