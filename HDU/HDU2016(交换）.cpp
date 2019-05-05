#include <stdio.h>
void sub(int *x , int *y)
{
	int temp = *x ;
	*x = *y;
	*y =temp;
}
int main()
{
	int n , a[100] , num;
	while(~scanf("%d" , &n) && n)
	{
		int min = 99999 ;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d" , &a[i]); 
		}
		for(int i = 0 ; i < n ; i++)
		{
			if(a[i] < min)
			{
				min = a[i];
				 num = i;
			}
		}
			sub(&a[num] , &a[0]);
			printf("%d" , a[0]);
		for(int i = 1 ; i < n ; i++)
		{
			printf(" %d" , a[i]);
		}
		printf("\n");
	}
	return 0;
 } 
