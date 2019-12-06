#include  <stdio.h>
#include  <iostream>

using namespace std;

#define lson l , m , rt << 1
#define rson m+1 , r , rt << 1|1

const int maxn = 222222;
int Max[maxn<<2];
int h , w , n;
void PushUp(int rt)
{
	Max[rt] = max(Max[rt << 1] , Max[rt << 1|1]);
}
void Build(int l , int r , int rt)
{
	Max[rt] = w;//用父节点保存子节点剩余的最大的广告长度。 
	if(l == r)
	{
		return; 
	}
	int m = (l + r) >> 1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}
int query(int x , int l , int r , int rt)
{
	if(l == r)
	{
		Max[rt] -= x;
		return l;
	}
	int m = (l + r) >> 1;
	int ret = (Max[rt<<1] >= x) ? query(x , lson) : query(x , rson);
	PushUp(rt);
	return ret;
}
int main()
{
	while(~scanf("%d %d %d" , &h , &w , &n))
	{
		if(h >= n)
		{
			h = n;
		}
		Build(1 , h , 1);
		while(n--)
		{
			int x;
			scanf("%d" , &x);
			if(Max[1] < x)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n" , query(x , 1 , h , 1));
			}
		}
	}
	return 0;
 } 
