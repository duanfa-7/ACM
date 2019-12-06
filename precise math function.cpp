#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;
#define PI acos(-1) 
int main()
{
	int t, n, x;
	scanf("%d" , &t);
	while(t--)
	{
		scanf("%d %d" , &n , &x);
		double ans = (double) pow(n,PI);
		printf("%.*f\n",x,ans);
	}
	return 0;
 } 
