#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std; 
int main ()
{
int a , b ;
int ans = 0 , sum = 0;
scanf("%d %d" , &a , &b);
for(int i = a ; i <= b ; i++)
{
	ans++;
	if(i >= 0 )
	{
		printf("%5d" , i);
	}
	else if (i < 0)
	{
		printf("%5d" , i);
	}
	
	sum += i;
	if(ans == 5 )
	{
		printf("\n");
		ans = 0 ;
	}
}
if(ans < 5 && ans > 0)
{
	printf("\n");
	printf("sum = %d" , sum);
}
else
{
	printf("sum = %d" , sum);
}

	return 0;
}
