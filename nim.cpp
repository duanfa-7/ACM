#include <stdio.h>
int main()
{
	int n,m;
	while(~scanf("%d" , &n))
	{
		int res = 0;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d" , &m);
			res ^= m;
		}
		if(res == 0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}
