#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstring>
using namespace std;
int a[5][5] , book[26][26];
int q[26] , w[26];
struct note
{
	int x;
	int y;
}s[100];
int top = 0 ;
int minn = 999999999;
void dfs(int x , int y , int step)
{
	book[x][y] = 1;
	int next[4][2] = {{0 , 1} , {1  , 0} , {0 , -1} , {-1 , 0}};
	if(x == 4 && y == 4)
	{
		if(step < minn)
		{
			minn = step;
			for(int i = 1 ; i <= top ; i++)
			{
				q[i] = s[i].x;
				w[i] = s[i].y;
			}
		}	
	return ;
	}
	int tx , ty;
	for(int k = 0 ; k <= 3 ; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if(tx < 0 || tx > 5 || ty < 0 || ty > 5)
		{
			continue;
		}
		if(a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			top++;
			s[top].x = tx;
			s[top].y = ty;
			
			dfs(tx ,ty , step + 1);
			book[tx][ty] = 0;
			top--;
		}
	}
	return;
}
int main()
{
	memset(book , 0 , sizeof(book));
	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			scanf("%d" , &a[i][j]);
		}
	}
	dfs(0 , 0 , 0);
	printf("(0, 0)\n");
	for(int i = 1 ; i < 26 ; i++)
	{
		if(q[i] == 0 && w[i] == 0)
		{
			break;
		}
	else if(q[i] == 4 && w[i] == 4)
	{
		break;
	}
	printf("(%d, %d)\n" , q[i] , w[i]);
	}
	printf("(4, 4)\n");
	return 0;
}
