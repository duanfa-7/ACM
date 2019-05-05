#include <stdio.h>
int main ()
{
	int n , m ;
	while(~scanf("%d %d" , &m , &n) && m >= 100 && n <= 999)
	{
		int flag = 0 , ans;
		if(m > n )
		{
			m = n;
		}
		for(int i = m ; i <= n ; i++)
		{
			ans = i ;
			if(ans == (ans / 100) * (ans / 100) *(ans / 100) +((ans / 10)%10) * ((ans / 10)%10) * ((ans / 10)%10) + (ans % 10) * (ans % 10) * (ans % 10) ) 
			{
				printf("%d " , ans);
				flag = 1;
			}
		}
		if(flag == 1)
		{
			printf("\n");
		}
	else
		{
			printf("no\n");
		}
		
	}
	return 0;
 } 
