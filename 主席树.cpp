#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],rt[maxn*20],ls[maxn*20],rs[maxn*20],sum[maxn*20];
int cnt,ql,qr,k;
void update(int pre,int& o,int l,int r,int pos)
{
	o=++cnt;
	ls[o]=ls[pre];
	rs[o]=rs[pre];
	//printf("%d %d\n",ls[o],rs[o]);
	sum[o]=sum[pre]+1;
	if(l==r)
	return;
	int m=(l+r)/2;
	if(pos<=m)
	update(ls[pre],ls[o],l,m,pos);
	else
	update(rs[pre],rs[o],m+1,r,pos);
}
int query(int pre,int o,int l,int r)
{
	if(l==r)
	return b[l];
	int m=(l+r)/2;
	int cmp=sum[ls[o]]-sum[ls[pre]];
	if(cmp>=k)
	return query(ls[pre],ls[o],l,m);
	else
	{
		k-=cmp;
		return query(rs[pre],rs[o],m+1,r);
	}
}
int main()
{
	int T;
	int n,q,i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		a[i]=b[i];
	}
	sort(b+1,b+n+1);
	int sz=unique(b+1,b+1+n)-(b+1);
	cnt=0;
	for(i=1;i<=n;i++)
	a[i]=lower_bound(b+1,b+1+sz,a[i])-b;
	for(i=1;i<=n;i++)
	update(rt[i-1],rt[i],1,sz,a[i]);
	while(q--)
	{
		scanf("%d%d%d",&ql,&qr,&k);
		printf("%d\n",query(rt[ql-1],rt[qr],1,sz));
	}
}

