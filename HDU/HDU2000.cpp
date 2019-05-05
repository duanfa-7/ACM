#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main ()
{
 
	float ans , x1 , x2 , y1 , y2;
	while(~scanf("%f%f%f%f" ,&x1 , &y1 , &x2 , &y2))
	{
		ans = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		printf("%.2f\n" , ans);
	}
	return 0;
}
