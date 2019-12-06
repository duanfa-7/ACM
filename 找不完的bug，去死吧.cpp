#include<iostream>
#include <stdio.h>
#include<string.h>
#define INF 0x3f3f3f3f
#include <map>
using namespace std;
int n , m , op;
const int maxn = 10000+8;
map<string , int>M , vis;
int Map[200][200] , book[200] , dis[200];
void Dijkstra()
{
	int u , minn;
	for(int i = 1 ; i < op-1 ; i++)
	{
		minn = INF;
		for(int j = 1 ; j < op ; j++)
		{
			
			if(book[j] == 0 && dis[j] < minn)
			{
				minn = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for(int j = 1 ; j < op ; j++)
		{
			
			if(book[j] == 0 && dis[j] > Map[u][j] +dis[u])
			{
				dis[j] = Map[u][j] +dis[u];
			}
		}
	}
}
int main()
{
	string start , end , s1 , s2 ;
	int t ;
	while(~scanf("%d" , &n) && n != -1)
	{
		op = 1;
		M.clear();
		memset(book , 0 , sizeof(book));
		memset(dis , 0 , sizeof(dis));
		cin >> start >> end;
		memset(Map , INF , sizeof(Map));	
		while(n--)
		{
			cin >> s1>> s2 >> t; 
			if(!M.count(s1))
			{
				M[s1] = op++;
			}
			if(!M.count(s2) )
			{
				M[s2] = op++;
			}
			if(Map[M[s1]][M[s2]] > t)
			{
				Map[M[s1]][M[s2]] = Map[M[s2]][M[s1]] = t;
			} 
		} 
		int S = M[start] , E = M[end];
		for(int i= 1 ; i <= op ; i++)
		{
			dis[i] = Map[S][i];
		}
		dis[S] = 0;
		book[S] = 1;
		Dijkstra();
		if(S == E) 
		{
			cout << "0" << endl;
			continue;
		}
		if(dis[E] == INF)
		{
			cout <<"-1"<<endl;
		}
		else{
			cout << dis[E] << endl;
		}
	}
	return 0;
 } 
 /*
 6
xiasha westlake
xiasha station 60
xiasha ShoppingCenterofHangZhou 30
station westlake 20
ShoppingCenterofHangZhou supermarket 10
xiasha supermarket 50
supermarket westlake 10
-1
 */
