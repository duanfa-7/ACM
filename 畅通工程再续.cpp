#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000+8;
int father[maxn];
int n;
struct node 
{
	int u;
	int v;
	int cost;
}s[maxn];
bool cmp(node a , node b)
{
	retrun a.cost < b.cost;
}
void init()
{
	for(int i = 0 ; i < n ; i++)
	{
		father[i] = i;
	}
}
int getf(int x)
{
	return x == father[x] ? x : father[x] = getf(father[x]);
}
bool merge(int x , int y)
{
	int fx = getf(x);
	int fy = getf(y);
	if(fx != fy)
	{
		father[fx] = fy;
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int T , x[maxn] , y[maxn] , k , ;
	double d;
	scanf("%d" , &T);
	while(T--)
	{
		k = 0;
		scanf("%d" , &n);
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d %d" , &x[i] , &y[i]);
		}
		for(int i = 0 ; i < n - 1 ; i++)
		{
			for(int j = i + 1 ; j < n ; j++)
			{
				d = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
				
			}
		}
		sort()
	}
	return 0;
}
