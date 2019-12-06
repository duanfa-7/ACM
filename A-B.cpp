#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s1[10005] , s2[10005];
	int flag = 0;
	gets(s1);
	gets(s2);

	for( int i = 0 ; s1[i] != '\0' ; i++)
	{
		flag = 0;
		for(int j = 0 ; s2[j] != '\0' ; j++)	
		{
			if(s1[i] == s2[j])
			{
				flag = 1;
			
			}
		}
		if(flag == 0)
		{
			printf("%c" , s1[i]);
		}
			
	}
	return 0;
}
