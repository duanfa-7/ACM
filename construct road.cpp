#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int INF = 100000;
int father[1000];
int edge[100][100] , T , x , y;
int getf(int x)
{
	return x == father[x] ? x : father[x] = getf(father[x]);
}
void init()
{
	for(int i = 0 ; i < T ; i++)
	{
		for(int j = 0 ; j < T ; j++)
		{
			if(i == j)
			{
				edge[i][j] = 0;
			}
			else
			{
				edge[i][j] = INF;
			}
		}
	}
 } 
int kruskal()
{
	
	int ans = 0 ;
	int fx = getf(x);
	int fy = getf(y);
	for(int i = 0 ; i < 1000 ; i++)
	{
		int min = 100000;
		for(int j = 0 ; j < 1000 ; j++)
		{
			if(fx != fy)
			{
				father[fx] = fy;
				if(edge[i][j] < min)
				{
					min = edge[i][j];
					ans += min;
					break;
				}
			}
			
		}
	}
	return ans;

}
int main ()
{
	int T , s , a , b;
	init();
		memset(father , 0 , sizeof(father));
	scanf("%d" , &T);
		for(int i = 0 ; i < T ; i++)
		{
			for(int j = 0 ; j < T ; j++)
			{
				scanf("%d" , &edge[i][j]);
			}
		}
		scanf("%d" , &s);
		while(s--)
		{
			scanf("%d %d" , &a , &b);
			edge[a][b] = 0;
		}
		cout << kruskal() << endl; 
	return 0;
 } 
