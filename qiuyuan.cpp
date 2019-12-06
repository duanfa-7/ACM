#include<stdio.h>
const double pi = 3.141592653589793238;
int main()
{
	double R,r,L;
	while(~scanf("%lf %lf %lf",&r, &R, &L))
	{
	if(r +R > L)
	{
	double x = (r * r - R*R + L*L) / (2.0 * L);
//	printf("x=%lf\n",x) ;
	double s1 = 4 * pi *r *r;
	double s2 = 4 * pi * R *R;
	double S = s1+ s2;
//	printf("S=%lf\n",S);
	double h1 = r - x;
	double h2 =R-(L -x);
//	printf("h1=%lf\n",h1);
//	printf("h2=%lf\n",h2);
	double res = S - 2 * pi *r*h1 - 2*pi*R*h2;
	printf("%.12lf\n",res);
	}
	else
	{
		double s1 = 4 * pi *r *r;
		double s2 = 4 * pi * R *R;
		double S = s1+ s2;
		printf("%.12lf\n",S);
	}
	
	
}
	
	
	return 0;
}
