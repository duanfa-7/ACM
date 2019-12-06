#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		int n = min(a , b);
		int m = max(a , b);
		double q = (double)(m-n);
		int k = (int)(q * (1+sqrt(5))/2.0);
		if(n == k)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}

	return 0;
}
