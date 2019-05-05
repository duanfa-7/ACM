#include <stdio.h>
int main ()
{
	int n , m , flag = 0;
	int a[105];
	int num = 0;
	for(int i = 2 ; i <= 200 ; i++)
	{
		if(i % 2 == 0)
		{
			a[num] = i;
			num++;
		 } 
	}
	while(~scanf("%d %d" , &n , &m ))
	{
		int sum = 0 , ans = 0;
		for(int i= 0 ; i < n ; i++)
		{
			sum += a[i];
			ans++;
			if(ans == m)
			{
				if(flag == 1)printf(" ");
				printf("%d" , sum / m);
				ans = 0;
				sum = 0;
				flag = 1;
			}
		}
		if(ans != 0)
		{
			printf(" %d\n" , sum / ans);
		}
		else
		{
			printf("\n");
		}
	flag = 0;
	}
	return 0;
}
