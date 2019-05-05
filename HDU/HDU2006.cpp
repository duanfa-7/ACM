#include <stdio.h>
int main()
{
	int n , m;
	while(~scanf("%d" , &n))
	{
		int ans = 1;
		while(n--)
		{
			scanf("%d" , &m);
			if(m % 2 != 0)
			{
				ans *= m;
			}
		}
		printf("%d" , ans);
	}
	return 0;
}
