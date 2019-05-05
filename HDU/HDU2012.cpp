#include <stdio.h>
int main ()
{
	int x , y;
	while(~scanf("%d %d" , &x , &y))
	{
		if(x == 0 && y == 0)//x , y 取值范围有负数 ， 挑出来 
		{
			break;
		}
		int flag = 0;
		for(int i = x ; i <= y ; i++)
		{
			int s = i * i + i + 41;
			for(int j = 2 ; j < s ; j++)
			{
				if(s % j == 0)
				{
					flag++;  //题目中是说判断是否都为素数 ，如果改成flag= 1的话， 则表示有非素即可 
					break;
				}
			}
		} 
		 	if(flag)
			{
				printf("Sorry\n");
				
			}
			else
			{
				printf("OK\n");
			}
	}
	return 0;
 } 
