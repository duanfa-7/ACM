#include <stdio.h>
int main ()
{
	long long int n , m;
	while(~scanf("%d %d" , &n , &m))
	{	
	long long int ans = 0 , vv = 0;
		if(n > m )
		{
			for(int i = m ; i <= n ; i++)
			{
				if(i % 2 == 0 )
				{
					ans += i * i;
				}
				else
				{
					vv += i * i * i;
				}
			}
			
		}
		else
		{
			for(int i = n ; i <= m ; i++)
			{
				if(i % 2 == 0 )
				{
					ans += i * i;
				}
				else
				{
					vv += i * i * i;
				}
			}
		}
		
		printf("%d %d\n" , ans , vv);
	}
	return 0;
 } 
