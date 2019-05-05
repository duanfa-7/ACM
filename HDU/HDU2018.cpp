#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	int n , a[100];
//, a[2] = 2 , a[3] = 3 , a[4] = 4 ;
	while(~scanf("%d" , &n) && n)
	{
		int num = 1 , ans = 0;
		memset(a , 0 , sizeof(a));
			a[1] = 1  , a[2] = 2 , a[3] = 3 ;
			for(int i = 4 ; i <= n ; i++)
			{
				a[i] = a[i - 3] + a[i - 1];
			}
			printf("%d\n" , a[n]);
	}

	return 0;
 } 
