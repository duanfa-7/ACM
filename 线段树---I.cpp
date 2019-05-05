#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>

#define lson l , m , rt<<1
#define rson m+1 , r , rt<<1|1

using namespace std;
const int maxn = 1e5+5;
struct node {
	int l , r;
};

node pic[maxn];
int change[maxn];
map<int , bool>via;
int cnt , tol;
int Max[maxn<<2] , Lazy[maxn];

void pushup(int rt)
{
	Max[rt] = max(Max[rt<<1] , Max[rt<<1|1]);
}
void pushdown(int rt)
{
	if(!Lazy[rt])
	{
		return;
	}
	Lazy[rt<<1] = Lazy[rt<<1|1] = Lazy[rt];
	Max[rt<<1] = Lazy[rt];
	Max[rt<<1|1] = Lazy[rt];
	Lazy[rt] = 0;	
}
void Build(int l , int r , int rt)
{
	Lazy[rt] = Max[rt] = 0;//��ʼΪ0 
	if(l == r)
	{
		return ;
	}
	int m = (l+r) >> 1;
	Build(lson);
	Build(rson);
}
//L , R ֮��Ķ��� �� ���Ϊ k , ��ʾ�ڼ��ź��� 
void update(int L , int R , int k , int l , int r , int rt)
{
	if(L <= l && R >= r)
	{
		Lazy[rt] = Max[rt] = k;
		return ;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if(L <= m) {
		update(L, R , k , lson);
	}
	if(R > m)
	{
		update(L , R , k , rson);
	}
	pushup(rt);
}
//ͳ�����ͬ��ĸ��� 
void Find(int l , int r , int rt)
{
	if(l == r)
	{
		if(via[Max[rt]]!=true && Max[rt] != 0)
		{
			tol++;
			via[Max[rt]] = true;
		}
		return ;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	Find(lson);
	Find(rson);
	pushup(rt); 
}
void init()
{
	cnt = 1;
	tol = 0;
	via.clear();
}
int main()
{
	int T ;
	cin >> T;
	while(T--)
	{
		init();
		int n;
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> pic[i].l>>pic[i].r;
			change[cnt++] = pic[i].l;
			change[cnt++] = pic[i].r;
		}
		sort(change , change+cnt);
		//ȥ��
		cnt = unique(change+1 , change+cnt+1) - change;
		Build(1 , cnt , 1);
		for(int i = 1 ; i <= n ; i++)
		{
			int L = lower_bound(change, change + cnt , pic[i].l) - change;
			int R = lower_bound(change , change + cnt , pic[i].r) - change;
			update(L , R , i , 1 , cnt , 1);
		 } 
		 Find(1 , cnt , 1);
		 cout << tol<<endl;
	}
	return 0;
}

