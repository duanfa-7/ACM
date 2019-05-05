#include <stdio.h>
int main ()
{
	int year , month , day;
	int x[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
	int y[12] = {31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
	while(~scanf("%d/%d/%d", &year , &month , &day) )
	{
	
		int ans = 0;
		if( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0 ))
		{
			for(int i = 0 ; i < 12 ; i++)
			{
				if(i < month - 1)
				{
					ans += y[i];
				}
			}
		}
		else
		{
			for(int i = 0 ; i < 12 ; i++)
			{
				if(i < month - 1)
				{
					ans += x[i];
				}
			}
		}
		printf("%d\n" ,  ans + day);
	}
	return 0;
 } 
