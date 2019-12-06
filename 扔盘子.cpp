#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n , m , a[50005] , b[50005] , ans = 0 , sum = 0 , wq;
	int book[50005];
	scanf("%d %d" , &n , &m);
	for(int j = 0 ;  j < n ; j++)
	{
		scanf("%d" , &b[j]);
		
	}
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%d" , &a[i]);
	}
	book[sum] = b[0]; 
	for(int i = 1 ; i < n; i++)
	{
		if(book[sum] > b[i])
		{
			sum++;
			book[sum] = b[i];
		}
		else
		{
			book[sum+1] = book[sum++];
		}
	 } 
	wq = n-1;
	for(int i = 0 ; i < m ; i++)
	{
	while(wq >= 0 && sum >= 0 )
		{
					if(a[i] <= b[wq] && a[i] <= book[sum] )
				{
					ans++;
					wq--;
					sum--;
					break;
				}
				else
				{
				sum--;
				wq--;
				}
			
		
		}
	}
	printf("%d\n" , ans); 
	return 0;
}
