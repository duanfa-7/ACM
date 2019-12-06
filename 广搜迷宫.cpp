#include <stdio.h>
struct node
{
	int x;
	int y;
	int step;
};
int a[51][51] , book[51][51];
int main()
{
	int i, j , k ,n , m , p , q ,startx , starty , flag , tx , ty;
	struct node que[2501];
	scanf("%d %d" , &n , &m);
	for(i = 1 ; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			scanf("%d" , &a[i][j]);
		}
	 } 
	 scanf("%d %d %d %d" , &startx , &starty , &p , &q);
	 flag = 0;
	 int next[4][2] = {{0,1} , {1 , 0} , {0 , -1} , {-1 , 0}};
	 int tail, head;
	 tail = 1;
	 head = 1;
	 que[tail].x = startx;
	 que[tail].y = starty;
	 book[startx][starty] = 1;
	 que[tail].step=0;
	 tail++;
	 while(head < tail)
	 {
	 	for(k = 0 ; k <= 3; k++)
	 	{
	 		tx = que[head].x+next[k][0];
	 		ty = que[head].y+next[k][1];
	 		if(tx <1 ||tx > n ||ty < 1||ty > m)
	 		{
	 			continue;
			 }
			 
			 if(a[tx][ty] == 0 && book[tx][ty] == 0)
			 {
			 	book[tx][ty] = 1;
			 	que[tail].x = tx;
			 	que[tail].y = ty;
			 	que[tail].step = que[head].step+1;
			 	tail++;
			 }
			 if(tx == p && ty == q)
			 {
			 	flag = 1;
			 	break;
			 }
		  } 
		  if(flag == 1)
		  {
		  	break;
		  }
		  head++;
	  } 
	 printf("%d" , que[tail-1].step);
	return 0;
 } 
