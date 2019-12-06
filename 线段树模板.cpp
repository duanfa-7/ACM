#include <cstdio>

#define lson l , m , rt << 1
#define rson m+1 , r , rt << 1|1 
const int maxn = 55555;
int Sum[maxn << 2];

//更新节点
void PushUp(int rt)
{
	Sum[rt] = Sum[rt << 1] + Sum[rt << 1|1];
}

//建树
void Build(int l , int r , int rt)
{
	if(l == r)
	{
		scanf("%d" , &Sum[rt]);
		return ;
	}
	int m = (l+r)/2;
	Build(lson);
	Build(rson);
	PushUp(rt);
}

//单点增减
void Update(int p , int add , int l , int r , int rt)
{
	if(l == r)
	{
		Sum[rt] += add;
		return ;
	}
	int m = (l + r)/2;
	if(p <= m)Update(p , add , lson);
	else Update(p , add , rson);
	PushUp(rt);
}

//区间求和
int query(int L , int R , int l , int r , int rt)
{
	if (L <= l && R >= r)
	{
		return Sum[rt];
	}
	int m = (l + r)/2;
	int ret = 0;
	if(L <= m )
	{
		ret += query(L,R , lson); 
	}
	if(R > m)
	{
		ret += query(L, R , rson);
	}
	return ret;
}
 
 //单点替换
 
 void Update(int p  , int sc, int l , int r , int rt)
 {
 	if(l == r)
 	{
 		Max[rt] = sc;
 		return ;
	 }
	 int m = (l + r)/2;
	 if(p <= m)Update(p , sc , lson);
	 else Update(p , sc , rson);
	 PushUp(rt);
 }
 
 //区间求最值
 
 void query(int L , int R , int l , int r , int rt)
 {
 	if(L <= l && R >= r)
 	{
 		return Max[rt];
	 }
	 int m = (l+r) >> 1;
	 int ret = 0;
	 if(L <= m) ret = max(ret , query(L , R , lson));
	 if(R > m ) ret = max(ret , query(L , R , rson));
	 return ret;
 }
 *******************************************************************
 //*****************************************************************
 *******************************************************************
 
 // 成段增减 
 
 //成段替换 
 
 
#include <stdio.h>
#include <iostream>
using namespace std;
int gcd(int x, int y){
	return y == 0 ? x:gcd(y,x%y) ; 
}
int main(){
	int a, b , c ,ans;
	while(~scanf("%d%d%d" , &a , &b , &c)&&(a+b+c)){
			if(a % 2 == 1){
				printf("NO\n");
			}
			else{
			int t = gcd(b,c);
			ans = a/t;
			if(ans % 2 == 0){
				printf("%d\n" , ans-1);
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 

