#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int maxn = 100005; 
int main()
{
	int n , m ,T, sum[maxn] , a[maxn] , res;
	scanf("%d" , &T);
	while(T--)
	{
		int flag = 0;
		scanf("%d %d" , &n , &m);
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d" ,&a[i] );
		} 
		for(int i = 0 ; i < n ; i++)
		{
			sum[i+1] = sum[i] + a[i];//sum 1-n
		}
		if(sum[n] <= m)
		{
		flag = 1;
			
		}
		 res = n;
		for(int s = 0 ; sum[s] + m <= sum[n] ; s++)
		{
			int t = lower_bound(sum+s , sum + n , sum[s] + m) - sum;
			res = min(res , t-s);
		}
		if(flag ==1 )
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n" , res);
		}
		
	}
	return 0;
}
