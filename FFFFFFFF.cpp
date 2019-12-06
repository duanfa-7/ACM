#include <iostream>
#include <stdio.h>

using namespace std;

#define lson l , m , rt<<1
#define rson m+1 , r , rt <<1|1

const int maxn = 200005; 
bool flag , f; // 猜测：标记已经进入的点 
int n , s[maxn<<2] , pos[maxn] , val[maxn] ,v[maxn] ; 
void PushUp(int rt)
{
	s[rt] = s[rt<<1]+s[rt << 1|1];//---更新父节点的空位 
}
void Build(int l , int r , int rt)
{

	if(l == r)
	{
		s[rt] = 1;//-----节点表示前面还有多少空位，这里初始为0 

		return; 
	}
	int m = (l + r) >> 1;
	Build(lson);
	Build(rson);
	PushUp(rt);
 } 
 void add(int z , int p , int l , int r , int rt)
 {
 	s[rt]--;
 	if(l == r)
 	{
 		v[rt] = p;	//-------表示位于该点的价值 ， 最后输出用 
 		return;
	 }
	 int m = (l+r) >> 1;
	 if(s[rt<<1] > z)add(z , p , lson);
	 else add(z,p-s[rt<<1],rson);
	 return;
 }
 int main()
 {
 	while(~scanf("%d" , &n))
 	{
	 	for(int i =1 ;  i <= n ; i++)
	 	{
	 		scanf("%d %d" , &pos[i] , &val[i]);
		 }
		 for(int i = n ; i >= 1; i--)
		 {
		 //	printf("pos[i] = %d        val[i] = %d\n" , pos[i] , val[i]);
		 add(pos[i] , val[i] , 0 , n , 1);
		 }
		 for(int i = 1 ; i <= 4*n ; i++)
		 {
		 	printf("s[i] = %d    " , s[i]);
		 	//printf("%d ",v[i]);
		 }
		 printf("\n");
	 }
	 return 0;
 }
 
