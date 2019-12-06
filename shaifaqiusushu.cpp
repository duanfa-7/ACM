#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 10000;
int a[maxn] , book[maxn];
int fun(int x)
{
		for(int i = 2 ; i < sqrt(x) ; i++)
		{
			if(x % i == 0)
			{
				return 0 ;
			}
			else 
			{
				return 1 ;//su 
			}
		}
}
int main ()
{
	memset(book , 1 , sizeof(book));
	book[0] = book[1] = 0;
	for(int i = 2 ; i < maxn ; i++)
	{
		for(int j = 1 ; j <= maxn ; j++)
		{
			if(fun(i))
			{
				book[i * j] = 0;
			}
			else
			{
				book[i] = 0;
			}
		}
		
	 } 
	return 0;
} 
