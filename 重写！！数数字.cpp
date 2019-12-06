#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int t , a , b , d , n , ans;
	while(~scanf("%d" , &t))
	{
		while(t--)
		{
			 ans = 0;
			scanf("%d %d %d %d" , &a , &b , &d , &n);
			int x = a*b;//
			int q = x%10;//个位 
			int w = x/10%10;//十位 
			int e = w+q;//中间 
			int flag = 0;
		//	printf("x = %d q = %d w = %d e = %d\n" , x , q , w , e);
		if(n == 1)
		{
			if(x <= 9 && x >= 0)
			{
				if(x == d)
				{
					printf("1\n");
				}
				else
				{
					printf("0\n");
				}
			}
			else
			{
				if(q == d || w == d)
				{
					printf("1\n");
				}
				else
				{
					printf("0\n");
				}
			}
		}
	else
		{
			if(0 <= x && x <= 9)
			{
				if(x==d)
				{
					flag = 1;
					printf("%d\n" , n);
				}
				else{
					flag = 1;
					printf("0\n");
				}
			}
			else{
				if(e >= 0 && e <= 9)
				{
					
						if(q == d)
						{
							flag = 1;
							printf("1\n");
						}
						if(w == d)
						{
							flag = 1;
							printf("1\n");
						}
						if(e == d)
						{
							flag = 1;
							printf("%d\n" , n-1);
						}
						if(flag == 0)
						{
							printf("0\n");
						}
				}
					else
					{
						int ff = e % 10;
						int hh = e/10 %10;
						if(q == d)
						{
							flag = 1;
							printf("1\n");
						}
						if(ff == d)
						{
								flag = 1;
							printf("1\n");
						}
						if(ff + hh == d)
						{
								flag = 1;
							printf("%d\n" , n-2);
						}
						if(w+hh == d)
						{
								flag = 1;
							printf("1\n");
						}
						if(flag == 0)
						{
							printf("0\n");
						}
					}
					
					
				}
		}
		
				
		}
	}
	return 0;
}
