#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n , j,ans,m  ,a[1000] , b[1000];
	while(~scanf("%d %d" , &n , &m))
	{
		ans=0;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d" , &a[i]);
		}
		for(int i = 0 ; i < m ; i++)
		{
			scanf("%d" , &b[i]);
		}
		for(int i = 0 ,j = 0; i < m &&j < n; i++,j++)
		{
			while( b[i] < a[j]&&i < m && j < n)
			{
				j++;
			}
			if(j == n)
			{
				break;
			}
			ans=i+1;
		}
		printf("%d\n" , ans);
	}
	return 0;
 } 
