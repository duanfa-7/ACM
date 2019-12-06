#include <bits/stdc++.h>
#define lson l , m , rt<<1
#define rson m+1 , r , rt<<1|1
using namespace std;
const int maxn = 1e4+8;
int sum[maxn<<2];
int lazy[maxn<<2]
void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void Build(int l , int r , int rt)
{
    lazy[rt] = 0;
    sum[rt] = 0;
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
        
    }
}
int main()
{

    return 0;
}