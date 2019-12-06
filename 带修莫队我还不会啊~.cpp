#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n , m , Q , a[maxn];
struct Query
{
	int l , r , Tim , ID , ans ;
	Query(){}
	Query(int _ID , int _l ,int _r ,int _Tim)
	{
		ID = _ID ;
		l = _l;r = _r;
		Tim = _Tim;
		ans = 0;
	 } 
} q[maxn];
struct Change
{
	int pos , New , Old;
	Change(){}
	change(int _pos , int _New , int _Old)//////
	{
		pos = _pos;
		New = _New ;
		Old == _Old;
	}
}c[maxn];
int block ,  l , r , T , ans , cnt[maxn*100] , pos[maxn] , now[maxn];
bool cmp(Query a  , Query b)
{
	return pos[a.l] == pos[b.l] ? (pos[a.r] == pos[b.r] ? a.Tim < b.Tim : a.r < b.r) : a.l < b.l;
}
bool cmp_id(Query a , Query b)
{
	return a.ID < b.ID;
}
void update(int x , int d)
{
	cnt[x] += d;
	if(cnt[x] == 0 && d == -1) ans--;
	if(cnt[x] == 1 && d == 1) ans++;
}
void change(int x , int d)
{
	if(l <= x && x <= r)
	{
		update(d , 1),
		update(a[x] , -1);
	}
	a[x] = d;
}
int main()
{
	scanf("%d %d" , &n , &m);
	block = pow(n , 2.0/3);//�ֿ� 
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d" , &a[i]);
		now[i] = a[i];//��¼û�и���ǰ���� 
		pos[i] = (i-1)/block+1;//�ֿ� 
	}
	while(m--)
	{
		char op;
		int x , y ;
		scanf("%c %d %d" , &op , &x , &y);
		if(op == 'Q')//ѯ�ʲ��� 
		{
			q[Q++] = Query(Q , x , y , T);//�ֱ��ʾ ID�� �� l , r , ʱ�� 
		}
		if(op == 'R') 
		{
			c[++T] =  Change(x , now[x] , y);//��ʾ��ǰλ�� �ĳ� y �� x�Ǵ�ʱtime���±� �� now[x]ָ����δ��֮ǰ��ʱ�� 
			now[x] = y;//�ĵ� 
		}
	 } 
	 sort(q , q+Q , cmp);
	l = 1 ; r = 0 ; T = 0 ; ans = 0;
	for(int i = 0 ; i< Q ; i++)
	{
		while(T < q[i].Tim) change(c[T].pos , c[++T].New); 
		while (T > q[i].Tim) change(c[T--].pos, c[T].Old);//�ȴ�����������Ȼ��T--
        while (l < q[i].l) update(a[l++], -1);
        while (l > q[i].l) update(a[--l],  1);
        while (r < q[i].r) update(a[++r],  1);
        while (r > q[i].r) update(a[r--], -1);
        q[i].ans = ans;
	}
	sort(q, q+Q, cmp_id);
    for (int i = 0; i < Q; i++) printf("%d\n", q[i].ans);
    return 0;
}   
