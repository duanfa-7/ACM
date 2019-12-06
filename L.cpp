#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
	double   x[105] , y[105] ,z[105] , r[105],cnt = 0 ;
	int t ;
while(~	scanf("%d" , &t)&&t)
{
			for(int i = 0 ; i < t ; i++)
		{
			scanf("%f %f %f %f" , &x[i] , &y[i] , &z[i] , &r[i]);
		}
		for(int i = 0 ; i < t-1; i++)
		{
		int	ans = (int)sqrt((x[i] -x[i+1])*(x[i] -x[i+1])+(y[i] -y[i+1])*(y[i] -y[i+1])+(z[i] -z[i+1])*(z[i] -z[i+1]))*1.0  ;
			printf("ans = %d\n" , ans);
			if(ans >= r[i]+r[i+1])
			{
				cnt += ans;
			}
		}
		if(cnt== 0)
		{
			printf("0.000\n");
		}
		else
		{
			printf("%.3f\n" , cnt);
		}
}

	return 0;
}
