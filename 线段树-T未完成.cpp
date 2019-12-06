#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define lson l , m , rt<<1
#define rson m+1 , r , rt<<1|1

const int maxn = 50060;
int lsum[maxn<<2] , rsum[maxn<<2] , msum[maxn<<2] , s[maxn<<2] , op[maxn<<2];
int n , m;

void Build(int l , int r , int rt)
{
	lsum[rt] = msum[rt] = rsum[rt] =r-l+1;//最开始的时候全都是连着的。所以长度为r-l+1
	if(l == r)
	{
		return;
	 } 
	 int m = (l+r) >> 1;
	 Build(lson);
	 Build(rson);
 } 
 void Update(int x , int flag ,int l , int r , int rt)//x表示修复或者破坏的数字 ， flag用来标记 是修复还是破坏 
 {
 	if(l == r)
 	{
 		if(flag == 1)
 		{
 			lsum[rt] =rsum[rt] = msum[rt] = 1;//修复 
		 }
		 else
		 {
		 	lsum[rt] = rsum[rt] = msum[rt] = 0;//破坏 
		 }
		 return ;
	  } 
	  int m = (l+r) >> 1;
	  if(x <= m)
	  {
	  	Update(x , flag , lson);
	  }
	  else
	  {
	  	Update(x , flag ,rson);
	  }
	  if(lsum[rt<<1] == r-l+1) lsum[rt] = lsum[rt<<1] + lsum[rt<<1|1];
	  else lsum[rt] = lsum[rt<<1];
	  if(rsum[rt<<1|1] == r-l+1)rsum[rt] =rsum[rt<<1|1] + rsum[rt<<1];
	  else rsum[rt] = rsum[rt<<1|1];
	  msum[rt] = max(lsum[rt<<1] +rsum[rt<<1|1] , max(lsum[rt] , rsum[rt<<1|1]));	
 }
 int search(int x ,int l , int r , int rt)
{
	if(l == r || msum[rt] == 0 || msum[rt] == r-l+1)
	{
		return msum[rt];
	}
	int m = (l + r) << 1;
	if(x <= m)
	{
		if(x >= (m-rsum[rt<<1]+1)) 
		{
			return rsum[rt<<1] + lsum[rt<<1|1]; 
		}
		else
		{
			return search(x , lson);
		}
	}
	else
	{
		if(x <= m+lsum[rt<<1|1]-1)
		{
			return lsum[rt<<1|1]+rsum[rt<<1];
		}
		else
		{
			return search(x , rson);
		}
	}
 } 
 
 int main()
 {
 	int x;
 	char ch[2];
 	while(~scanf("%d %d" , &n , &m))
 	{
 		int top = 0;
 		Build(1,n,1);
 		while(m--)
 		{
 			scanf("%s" ,ch);
 			if(ch[0]== 'D')
 			{
 				scanf("%d" , &x);
 				op[top++] = x;
 				Update(x,0,1,n,1);
			 }
			 else if(ch[0] == 'Q')
			 {
			 	scanf("%d" , &x);
			 	printf("%d\n" , search(x,1,n,1));
			 }v
			 else
			 {
			 	x = op[--top];
			 	Update(x,1,1,n,1);
			 }
		 }
	 }
 	return 0;
 }
 
 
 
