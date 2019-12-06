#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int n , k , ans;
char a[10][10];
int vis[10];
int dfs(int x , int k)
{
	if(k == 0)
	{
		ans++;
		return 0;
	}
	if(x == n+1)
	{
		return 0;
	}
	//	for(int i = x ; i <= n ; i++)
	//	{
			for(int j = 1 ; j <= n ; j++)
			{
				if(a[x][j] == '#' && vis[j] == 0)
				{
					vis[j] = 1;
					dfs(x+1 , k-1);
					vis[j] = 0;
				
				}
			//	x++;
			}
			dfs(x+1,k);
	//	}
		
	return 0;
}
int main()
{
	while(~scanf("%d %d" , &n , &k) )
	{
		if(n == -1 && k == -1)
		{
			break;
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				cin >> a[i][j];
			}
		}
		ans = 0;
		memset(vis , 0 , sizeof(vis));
		dfs(1 , k);
		printf("%d\n" , ans);
	 } 
	return 0;
}
