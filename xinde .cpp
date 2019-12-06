#include <string.h>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
map<string,int>M;
int main()
{
	char str1[2008] , str2[2008];
	int n , ha = 0 , da = 0 , ra = 0 , we = 0;
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> str1;
		cin >> str2;
		int len = strlen(str1);
		for(int j =  ; j < len ; j++)
		{
			if(str2[i] == 'h')
			{
				ha++;
			}
			else if(str2[i] == 'r')
			{
				ra++;
			}
			else if(str2[i] == 'd')
			{
				da++;
			}
			else
			{
				we++;
			}
		}
		int opp = (int)(1.0*len*0.25);
		int op = (int)(1.0*len*0.1);
		if(M["h"] >= opp)
		{
			printf("Case #%d: Harmful\n" , i);
		}
		else if(M["h"] >= 0 && M["h"] <= op)
		{
			printf("Case #%d: Recyclable\n" , i);
		}
		else
		{
			if(M["d"] >= 2*M["w"])
			{
				printf("Case #%d: Dry\n" , i);
			}
			else
			{
				printf("Case #%d: Wet\n" , i);
			}
		}
	}
	return 0;
}