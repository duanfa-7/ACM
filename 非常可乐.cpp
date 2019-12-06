#include <stdio.h>
#include <iostream>
using namespace std;
int gcd(int x, int y)
{
	
	return y == 0 ? x:gcd(y,x%y) ; 
}
int main()
{
	int a, b , c ,ans;
	while(~scanf("%d%d%d" , &a , &b , &c)&&(a+b+c))
	{
			if(a % 2 == 1)
			{
				printf("NO\n");
			}
			else
		{
			int t = gcd(b,c);
			ans = a/t;
		//printf("%d\n" , ans;
		if(ans % 2 == 0)
		{
			printf("%d\n" , ans-1);
		}
		else
		{
			printf("NO\n");
		}
		}
	
	}
	return 0;
}
