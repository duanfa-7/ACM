#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
#define N 10005
int book[N];
int a[N];
int b[N];
int ans = 0;
void init()
{
	a[1] = 1;
	//int ans = 0;
	for(int i = 2 ; i <= sqrt(N) ; i++)
	{
		if(a[i] == 0)
		{
			for(int j = 2 ; i * j <= N ; j++)
			{
				a[i * j] = 1;
			}
		}
	}
	for(int i = 0 ; i <= N ; i++)
	{
		if(a[i] == 0)
		{
		b[ans] = i;
		ans++;
		}
		
	}
	//printf("ans = %d" , ans); 
	
}
int main()
{
	init();
	printf("ans = %d\n" , ans);
	for(int i = 0 ; i < 100 ; i++)
	{
	//	printf("b[i] = %d" , b[i]);
	//	printf("7777");
		for(int j = i + 1 ; j < 100 ; j++)
		{
		//	printf("999");
	//	printf("b[j] - b[i] = %d\n" , b[j] - b[i]);
	//	break;
			book[b[j] - b[i]]++;
		}
	//	printf("111");
	}
	printf("000");
	for(int i = 0 ; i < ans ; i++)
	{
	//	printf("book[i] = %d\n" , book[i]);
	//	printf("7777");
		if(book[i] == 6)
		{
		//	printf("999");
			printf("i = %d" , i);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
