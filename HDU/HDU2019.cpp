#include <stdio.h>
#include <iostream>
using namespace std;
#include <algorithm>
int main ()
{
	int n , m , a[100];
	while(~scanf("%d %d" , &n , &m ) && (n + m))
	{
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d" , &a[i]);
			a[n] = m;
		}

		for(int i = 0 ; i <= n ; i++)
		{
		
		}
		sort(a , a + n + 1);
		printf("%d" , a[0]);
			for(int i = 1 ; i <= n ; i++)
		{
			
			printf(" %d" , a[i]);
		}
		cout << endl;
	}
	return 0;
 } 
