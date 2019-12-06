#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
	
	long long int n , m , T ,a[100055] , res;
	scanf("%lld" , &T);
	while(T--)
	{
long long int t = 0 , s = 0 ,sum = 0 ;
		scanf("%lld %lld" , &n , &m);
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%lld" , &a[i]);
		}
		res = n + 1;
		while(1)
		{
			while(t < n && sum < m)
			{
				sum += a[t];
				t++;
			}
			if(sum < m)
			{
			//	printf("0\n");
				break;
			}
			res = min(res,t-s);
			sum -= a[s];
			s++;
		}
		if(res > n)
		{
			res = 0;
		}
			printf("%lld\n" , res);
	}

	return 0;
}

