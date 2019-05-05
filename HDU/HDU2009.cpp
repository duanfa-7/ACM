#include <stdio.h>
#include <math.h>
int main ()
{
	double n , m ;
	while(~scanf("%lf %lf" , &n , &m))
	{
		double ans = 0;
		while(m--)
		{
			ans += n;
			n = sqrt(n);
		}
		printf("%.2lf\n" , ans);
	}
	return 0;
}
