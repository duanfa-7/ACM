#include <bits/stdc++.h>
using namespace std;
bool judge(int x)
{
	if(x == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	int n ;
	
	while(~scanf("%d" , &n)&&n)
	{
		int a[10005];
		memset(a , 0 , sizeof(a));
	a[1] = 1;
	for(int i = 2 ; i <= n ; i++)
	{
	
		if(a[i] == 0)
		{
			for(int j = 2 ; i * j <= n ; j++)
			{
				a[i*j] = 1;
			}
		 } 
	}
//	for(int i = 1 ; i  <= n ; i++)
//	{
//		if(judge(a[i]) == 1)
//		{
//			printf("i = %d  " , i);
//		}
//	}
//	printf("\n");
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i++)
		{
			if(a[i] == 0)
			{
				if(judge(a[n-i]) == 1) 
				{
			//		printf("n-i = %d\n" , n-i);
					ans++;
				}
			}
			
		}
		printf("%d\n" , ans/2);
	}
	return 0;
}
