#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	scanf("%d" , &n);
	int i , j , len , start , flag = 0 , k ;
	for(int len = 12 ; len >= 1 ; len--)
	{
			 k = sqrt(n) + 1;
		for(start = 2 ; start <= k ; start++)
		{
			long long sum = 1;
			for(int i = start , j = 0 ; j < len ; j++ , i++)
			{
				sum *= i;
			}
			if(n % sum == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			break;
		}
	}
	
	
	 if(flag)
	 {
	 	printf("%d" , len);
	 	for(i = start , j = 0; j < len ; j++ , i++)
	 	{
	 		printf("%d%c" , i , j == len - 1 ? '\n' : '*');
		 }
	 }
	 else
	 {
	 	printf("1\n%d\n" , n);
	 }
	return 0;
 } 
