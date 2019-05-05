#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
bool cmp(int a , int b)
{
	if(a < b)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	int n , book[1000000] , a[105];
	while(~scanf("%d" , &n) && n)
	{
		memset(book , 0 , sizeof(book));
		for(int i = 0 ; i  < n ; i++)
		{
			cin >> a[i];
			if(a[i] < 0)
			{	
				a[i] = -a[i];
				book[a[i]] = 1;
			}
		}
		sort(a , a+n , cmp);
		for(int i = 0 ; i < n ; i++)
		{
			if(book[a[i]] == 1)
			{
				printf("-%d " ,a[i]);
			}
			else if( i == n-1)
			{
				printf("%d" , a[i]);
			}
			else
			{
				printf("%d " , a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
 
