#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn = 100050;
int father[maxn] , vis[maxn] ,flag , ans;
void init()
{
	for(int i = 1 ; i <= maxn ; i++)
	{
		father[i] = i;
		vis[i] = 0;
	}
}
int getf(int x)
{
	return x == father[x] ? x : father[x] = getf(father[x]);
}
void merge(int x , int y)
{
	vis[x] = 1;
	vis[y] = 1;
	int fx = getf(x);
	int fy = getf(y);
	if(fx != fy)
	{
		father[fx] = fy;
	}
	else
	{
		vis[fx] = 0	;//说明有环 
		
	}
}
void find (int x)
{
	if(vis[x] == 1)
	{
		vis[x] = 0;
		find(father[x]);
		vis[x] = 1;
	}
	else
	{
		ans = x;
	}
	return;
}
map<string , int>M;
int main()
{	
init();
	int n , num;
	string s1 , s2;
	scanf("%d" , &n);
	int t = 0;
	while(n--)
	{
		cin >> num >> s1 >> s2;
		while(!M.count(s1))
		{
			M[s1] = t++;
		}
		while(!M.count(s2))
		{
			M[s2] = t++;
		}
		if(num == 0)
		{
			merge(M[s1] , M[s2]);
		}
		else
		{
			if( getf(M[s1]) == getf(M[s2]) )
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		} 
	}

	return 0;
}
