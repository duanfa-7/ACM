#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int n, m;
	while(~scanf("%d %d" ,&n,&m))
	{
		int a = min(n,m);
		int b = max(n,m);
		double k = (double)(b-a);
		int ans = (int)(k*(sqrt(5)+1)/2);
		if(ans == a)
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
