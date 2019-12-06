#include <cstdio>

#define lson l , m , rt << 1
#define rson m+1 , r , rt << 1|1
const int maxn = 55555;
int Sum[maxn << 2];

void PushUp(int rt)//更新节点 
{
	Sum[rt] = Sum[rt << 1] + Sum[rt << 1|1];
 } 
 
 void Build(int l, int r , int rt)//建树 
 {
 	if(l == r)
 	{
 		scanf("%d" , &Sum[rt]);
 		return;
	 }
	 	int m = (l+r)>>1;
	 	Build(lson);
	 	Build(rson);
		 PushUp(rt);
 }
 
 void Update(int p , int add , int l , int r , int rt)//单点增减 
 {
 	if(l == r)
 	{
 		Sum[rt] += add;
 		return ;
	 }
	 
	 	int m = (l+r)>>1;
	 	if(p <= m)
	 	{
	 		Update(p , add , lson);
		 }
		 else
		 {
		 	Update(p , add , rson);
		 }
	  PushUp(rt);
  } 
 
 int query(int L , int R ,int l , int r , int rt)//区间求和
 {
 	
 	if(L <= l && R >= r)
 	{
 		return Sum[rt];
	 }
	 int m = (l + r) >> 1;
	 int ret = 0;
	 if(L <= m)
	 {
	 ret +=	query(L , R , lson);
	 }
	 if(R > m)
	 {
	 ret +=	query(L , R , rson);
	 }
	 return ret;
  } 
 
 int main()
 {
 	int T , n;
 	scanf("%d" , &T);
 	for(int cas = 1 ; cas <= T ; cas++)
 	{
 		printf("Case %d:\n" , cas);
 		scanf("%d" , &n);
 		Build(1 , n , 1);
 		char op[10];
 		while(scanf("%s" , op))
 		{
 			if(op[0] == 'E')break;
 			int a , b;
 			scanf("%d %d" , &a , &b);
 			if(op[0] == 'Q')printf("%d\n" , query(a , b , 1 , n , 1 ));
 			else if(op[0] == 'S')Update(a , -b , 1 , n , 1);
 			else Update(a ,b , 1 , n , 1);
		 }
	}
	return 0; 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
