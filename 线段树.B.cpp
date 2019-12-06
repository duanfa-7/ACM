#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define lson l , m , rt << 1
#define rson m+1 , r , rt << 1|1 
const int maxn = 222222;
int Sum[maxn << 2];
//更新节点
void PushUp(int rt)
{
	Sum[rt] = max(Sum[rt << 1] , Sum[rt << 1|1]);
}

//建树
void Build(int l , int r , int rt)
{
	if(l == r)
	{
		scanf("%d" , &Sum[rt]);
		return ;
	}
	int m = (l+r)>>1;
	Build(lson);
	Build(rson);
	PushUp(rt);
}
void Update(int p  , int sc, int l , int r , int rt)
 {
 	if(l == r)
 	{
 		Sum[rt] = sc;
 		return ;
	 }
	 int m = (l + r)/2;
	 if(p <= m)Update(p , sc , lson);
	 else Update(p , sc , rson);
	 PushUp(rt);
 }
 
 //区间求最值
 
 int query(int L , int R , int l , int r , int rt)
 {
 	if(L <= l && R >= r)
 	{
 		return Sum[rt];
	}
	 int m = (l+r) >> 1;
	 int ret = 0;
	 if(L <= m) ret = max(ret , query(L , R , lson));
	 if(R > m ) ret = max(ret , query(L , R , rson));
	 return ret;
 }
 int main()
 {
 	int N , M ;
 	
 	while(~scanf("%d %d" , &N , &M))
 	{
 		Build(1 , N , 1);
		while(M--)
		 {
		 	char ch[2];
		 	int num1 , num2;
		 	scanf("%s%d%d" , ch , &num1 , &num2);
		 	if(ch[0] == 'Q')
			{
				printf("%d\n" , query(num1 , num2 , 1, N ,1));
			}
			else 
			{
				Update(num1 , num2 , 1 , N , 1);
			}
		 }
	}
 	return 0;
  } 
