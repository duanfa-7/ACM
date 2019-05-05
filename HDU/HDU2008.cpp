#include <stdio.h>
int main ()
{
	int n ;
	double m;
	while(~scanf("%d" , &n) && n)
	{
		int a = 0 , b = 0 , c = 0;
		while(n--)
		{
			scanf("%lf" , &m);
			if(m < 0 )
			{
				a++;
			}
			else if (m > 0 )
			{
				c++;
			 } 
			 else
			 {
			 	b++; 
			 }
			
		}
		printf("%d %d %d\n" , a , b , c);
	}
	return 0;
 } 
