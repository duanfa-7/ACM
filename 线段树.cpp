#include <stdio.h>
#include <iostream>
using namespace std;

#define lson l , m , rt << 1
#define rson m+1 , r , rt <<1|1

const int maxn = 222222;
int Max[rt << 2];
int h,w , n;

void PushUp(int rt)
{
	Max[rt] = max(Max[rt << 1] , Max[rt << 1|1]);
}
void Build(int l , int r , int rt)
{
	Max[rt] = w;
	if(l == r)
	{
		return;
	}
	int m = (l + r) >> 1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

