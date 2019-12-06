#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 2003;
int sg[maxn] , Hash[maxn] , a , b , c;
int getsg(int x)
{
	memset(sg , -1 , sizeof(sg));
	if(sg[x] != -1)return sg[x];
	memset(Hash , 0 , sizeof(Hash));
	if(x >= a)
	{
		for(int i = 1; i<=x-a+1 ; i++)
		{
			Hash[getsg(i-1) ^ getsg(x-a+1-i)] = 1;
		}
	}
		if(x >=b)
	{
		for(int i = 1; i<=x-b+1 ; i++)
		{
			Hash[getsg(i-1) ^ getsg(x-b+1-i)] = 1;
		}
	}
		if(x >= c)
	{
		for(int i = 1; i<=x-c+1 ; i++)
		{
			Hash[getsg(i-1) ^ getsg(x-c+1-i)] = 1;
		}
	}
	for(int i = 0 ; i <= x ; i++)
	{
		if(Hash[i] == 0)
		{
			sg[x] = i;
			return sg[x];
		}
	}
}
int main()
{
	int  t , x;
	scanf("%d %d %d" , &a , &b , &c);
	scanf("%d" , &t);
//	memset(sg , -1 , sizeof(sg));
	for(int i = 0 ; i < min(a , min(b , c)); i++)
	{
		sg[i] = 0;
	}
	for(int i = 1 ; i<= t ; i++)
	{
		scanf("%d" , &x);
		getsg(x);
		if(sg[x])puts("1");
		else puts("2");
	}
	return 0;
}
/*
1 5 1 
3
1
5
6

*/
