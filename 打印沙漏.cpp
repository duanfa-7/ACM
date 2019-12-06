#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
	int n;
	int x , y;
	char ch;
	while(~scanf("%d" , &n))
	{
			cin >> ch;
	for(int i = 1 ; i <= n ; i++)
	{
		if(i * i <= (n + 1) / 2)
		{
			x = i;
			y = i * i * 2 - 1;
		}
		else
		{
			break;
		}
	}

	for(int i = x  ; i > 1 ; i--)
	{
		for(int j = x - i ; j > 0 ; j--)
		{
			printf(" ");
		}
		for(int k = 1 ; k <= 2 * i - 1 ; k++)
		{
			cout << ch;
		}
		 printf("\n");
	}
	for(int i = 1 ; i <= x ; i++)
	{
		for(int j = i ; j <= x - 1 ; j++)
		{
			printf(" ");
			
		}
	
		for(int k = 1 ; k <= 2 * i - 1 ; k++)
		{
			cout << ch;
		}
			printf("\n");
	}
	printf("%d\n" , n - y);
	}

	return 0;
 } 
