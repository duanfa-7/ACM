#include <bits/stdc++.h>
#define PI acos(-1.0)
#define ll long long
using namespace std;
int main()
{
	int t;
//	long long double a;
	double a , b , r , d , ans;
	scanf("%d" , &t);
	while(t--)
	{
		cin >> a >> b >> r >> d;
		d = d / 180.0 * PI;
		double h = (a+r)*tan(d);
		printf("h = %llf\n" , h);
		//if(h != b)
	//	{
			ans = sqrt(b*b+(a+r)*(a+r))-r;
			printf("1 = %llf\n" , ans);
	//	}
	//	else
	//	{
			ans = b*sin(d) + a*cos(d) +r*cos(d) - r;
				printf("2 = %llf\n" , ans);
	//	}
		printf("%.12lf\n" , ans);
	 } 
	return 0;
 } 
