#include <stdio.h>
#include <iostream>
using namespace std;

#define lson l , m , rt<<1
#define rson m+1 , r , rt <<1|1

const int maxn =111111;
long long Sum[maxn << 2];
long long add[maxn << 2];

void PushUp(int rt)
{
	Sum[rt] = Sum[rt << 1] + Sum[rt << 1|1];
 } 
 void PushDown(int rt , int m)
 {
 	if(add[rt] != 0)
 	{
 		add[rt << 1] += add[rt];
 		add[rt <<1|1] += add[rt];
 		Sum[rt << 1] +=(m-m/2)*add[rt];
 		Sum[rt <<1|1] += (m/2) * add[rt];
 		add[rt] = 0;
	 }
 }
void Build(int l , int r , int rt)
{
	add[rt] = 0;
	if(l == r)
	{
		scanf("%lld" , &Sum[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	Build(lson);
	Build(rson);
	PushUp(rt);
 } 
void Update(int p , int L , int R , int l , int r , int rt)
 {
 	if(L <=l && r <= R)
	{
		add[rt] += p;
		Sum[rt] += (long long)(r-l+1) *p;
		return;
	}
	PushDown(rt , r-l+1);
	 int m = (l+r) >> 1;
	 if(L <= m) Update(p , L , R , lson);
	 if(R > m) Update(p , L , R , rson);
	 PushUp(rt);
	 
 }
long long  query(int L , int R , int l , int r , int rt)
 {
 	if(L <= l && r <= R)
 	{
 		return Sum[rt];
	 }
	 PushDown(rt , r-l+1);
	 int m = (l + r) >> 1;
	 long long ret = 0;
	 if(L <= m) ret += query(L , R , lson);
	 if(R > m) ret += query(L , R , rson);
	 return ret;
 }
 
int main()
{
	char ch[2];
	int n , m , x , a , b , c , ans;
	scanf("%d %d" , &n , &m);
	Build(1 , n , 1);
		while(m--)
			{
				
			//	printf("m = %d\n" , m);
			scanf("%s" , &ch);
			if(ch[0] == 'Q')
			{
				scanf("%d %d" , &a , &b);
				printf("%d\n" , query(a , b , 1 , n , 1));
			}
			else
			{
				scanf("%d %d %d" , &a , &b , &c);
				Update(c , a , b , 1 , n , 1);
			}
		}
	return 0;
 } 
