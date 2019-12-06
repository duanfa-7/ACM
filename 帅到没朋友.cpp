#include <stdio.h>
int main()
{
	int n , m , a , b[100000] , num = 1 , q ,w , flag = 0 , ans = 0 , wq = 0 , yy = 0 , pp = 0;
	scanf("%d" , &n);
	b[0] = 0;
	while(n--)
	{
	
		scanf("%d" , &m);
		for(int i = 0 ; i < m ; i++)
		{
			scanf("%d" , &a);
			if(m == 1)
			{
				b[0] = a;
			} 
			else
			{
				b[num] = a;
				num++;
			}
		}
	}
	scanf("%d" , &w);
	int t = w;
	while(w--)
	{
		scanf("%d" , &q);
		flag = 0;
		for(int i = 1 ; i < num ; i++)
		{
			if(q == b[i] && q == b[0])
			{
				yy = 1;
			}
		}
	
		for(int i = 0 ; i < num ; i++)
			{ 
			if(q == b[i])
				{
					ans++;
					flag = 1;
					break;
				}
			}
			if(flag == 0 )
			{
				pp++;
			}
		num++;
		b[num] = q;
		if(flag == 0)
		{
			if(yy == 1)
			{
					if(pp == 1)
				{
					printf("%00000dll" , q);
				}
				
				else
				{
					printf("%00000d " , q);
				}
			}
			else
			{
				if(pp == 1)
				{
					printf("%d" , b[0]);
				}
				printf("%00000d " , q);
			}
			
		}
	//	printf("w = %d" , w);
	}
//	printf("ans = %d" , ans);
//	printf(" t == %d" , t);

		if(ans == t )
		{
			
			printf("No one is handsome\n");
		}


	
	return 0 ;
 } 
/*
2
3 11111 22222 33333 
1 55555
4
11111 55555 77777 88888
*/
