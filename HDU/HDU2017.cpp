#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main ()
{
	int n;
	char str[10000];
	while(~scanf("%d" , &n))
	{
			while(n--)
		{
			int ans = 0;
			scanf("%s" , str); 
			int l = strlen(str);
			for(int i = 0 ; i < l ; i++)
			{
				if(str[i] <= '9' && str[i] >= '0')
				{
					ans++; 
				}
			}
			printf("%d\n" , ans);
		}
	 } 
	
	return 0 ;
 } 
