#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int book[10];
int main()
{
	int x , y , n ;
	int ans = 0 , num = 0;
	scanf("%d %d" , &x , &y);
	for(int i = x ; i <= 3020 ; i++)
	{
		n = i;
		num = 0;
		memset(book , 0 , sizeof(book));
		if(i > 0 && i < 1000)
		{
			while(n)
			{
				book[0] = 1;
				book[n % 10] = 1;
				n = n / 10;
			}
		}
		else
		{
			while(n)
			{
				book[n % 10] = 1;
				n = n / 10;
			}
		}
		
		for(int j = 0 ; j < 10 ; j++)
		{
			if(book[j] == 1)
			{
				num++;
			}
		}
		if(num == y)
		{
			printf("%d %04d" , ans , i);break;
		}
		ans++;
	}
	return 0;
}
