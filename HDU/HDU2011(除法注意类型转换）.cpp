#include <stdio.h>
int main ()
{
	float n , ans , m;
	scanf("%f" , &m);
	while(m--)
	{
		ans = 0;
		scanf("%f" , &n);
		for(int i = 1 ; i <= n ; i++)
		{
			if(i % 2 != 0)
			{
				ans += (1.0/i);
			}
			else
			{
				ans  = ans - (1.0/i);
			//	printf("ans = %.2f " ,ans);
			}
		}
		printf("%.2f\n" , ans);
	}
	return 0;
}
