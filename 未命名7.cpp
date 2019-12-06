#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int phi(int x)//Å·À­º¯Êý
{
	int i,j;
	int num = x;
	for(i = 2; i*i <= x; i++)
	{
		if(x % i == 0)
		{
			num = (num/i)*(i-1);
			while(x % i == 0)
			{
				x = x / i;
			}
		}
	}
	if(x != 1) num = (num/x)*(x-1);
	return num;
}
int main()
{
	for(int i = 1 ; i <= 20 ; i++)
	{
		printf("%d : %d\n" , i , phi(i));
	}
	return 0;
}
