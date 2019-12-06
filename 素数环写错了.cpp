#include <stdio.h>
bool book[1000];
int vist[1000];
int n;
bool fun(int x)
{
	if(x == 0 || x == 1)
	{
		return false;
	}
	for(int i = 2 ; i < x ; i++)
	{
		if(x % i == 0 )
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
int dfs(int step)
{
	if(step == n)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			printf("%d" , vist[i]);
		}
	//	return;
	}
	else
	{
		for(int i = 1 ; i <= n ; i++)
		{
			if(book[i] == 0)
			{
				book[i] = 1;
				vist[i] = i;
				dfs(step+1);
			}	
		}
		//return ;
	}
}
int main()
{
	int n , num = 1;
	while(~scanf("%d" , &n))
	{
		
		printf("CASE#%d:" , num);
		dfs(0);
		num++;
	 } 
	
	return 0 ;
 } 
