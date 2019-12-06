#include <bits/stdc++.h>
#define lson l,m;
#define rson m+1,r;
using namespace std;
const int maxn = 2e5 + 10;
int n, q,k;
int rt[maxn] , ls[maxn] ,rs[maxn] , sum[maxn] ,cnt;
void update(int pre,int o,int l,int r,int pos)
{
    o = ++cnt;
    ls[o] = ls[pre];
    rs[o] = rs[pre];
    sum[o] = sum[pre]+1;
    if(l == r) return ;
    int m = (l+r)>>1;
    if(pos <= m) update(ls[pre],ls[o],lson,pos);
    else update(rs[pre],rs[o],rson,pos);
}
int query(int pre,int o,int l,int r,int pos)
{
    if(l == r) return b[l];
    int now = sum[ls[o]] - sum[ls[pre]];
    int m = (l+r)>>1;
    if(now <= k) return query(ls[pre],ls[o],lson,pos);
    else 
    {
        k -= now;
        return query(rs[pre],rs[o],m+1,r,pos);
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b,b+n);
    int sz = unique(b+1,b+n+1) - b - 1;
    for(int i = 1 ; i <= n ; i++) a[i] = lower_bound(b+1,b+n+1,a[i]) - b;
    for(int i = 1 ; i <= n ; i++) update(rt[i] , rt[i-1],1,sz,a[i]);
    while(q--)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        printf("%d\n",query(rt[L-1] , rt[R],1,sz));
    }
    
}