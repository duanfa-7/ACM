#include <bits/stdc++.h>
typedef long long LL;
const int maxn = 50000+6;
int n , Q , a[maxn] , cnt[maxn] , pos[maxn];
int l , r , block;
LL sum;
struct Query
{
	int l , r , ID;
	LL A , B; 
}q[maxn];
bool cmp1(Query a , Query b)
{
	return pos[a.l] != pos[b.l] ? a.l < b.l : a.r < b.r;
}
bool cmp2(Query a , Query b)
{
	return a.ID < b.ID;
}
using namespace std;
int update(int x , int d)
{
	sum -= cnt[x] * (cnt[x]-1);
	cnt[x] += d;
	sum += cnt[x] * (cnt[x]-1);
}
int main()
{
	scanf("%d %d" , &n , &Q);
	block = sqrt(n);
	
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d" , &a[i]);
		pos[i] = (i-1)/block+1;
	}
	for(int i = 0 ; i < Q ; i++)
	{
		scanf("%d %d" , &q[i].l , &q[i].r);
		q[i].ID = i;
	}
	sort(q , q+Q , cmp1);
	l = 1 ;
	r = 0 ;
	sum = 0;
	for(int i = 0 ; i < Q ; i++)
	{
		while(l < q[i].l)update(a[l++] , -1);
		while(l > q[i].l)update(a[--l] , 1);
		while(r > q[i].r)update(a[r--] , -1);
		while(r < q[i].r)update(a[++r] , 1);
		if(q[i].l == q[i].r)
		{
			q[i].A = 0;
			q[i].B = 1;
			continue;
		}
		q[i].A = sum;
		q[i].B = 1LL*(r-l+1) * (r-l);
		LL M = __gcd(q[i].A , q[i].B);
		q[i].A /= M;
		q[i].B /= M;
	}
	sort(q , q+Q , cmp2);
	for(int i = 0 ; i < Q ; i++)
	{
		printf("%lld/%lld\n" ,q[i].A , q[i].B);
	}
	return 0;
}
