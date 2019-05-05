#include <stdio.h>
#define PI 3.1415927
int main ()
{
	double r , ans; 
	while(~scanf("%lf" , &r))
	{
		ans = PI * r * r * r * 4/3;
		printf("%.3lf\n" , ans);
	}
	
	return 0 ;
}
