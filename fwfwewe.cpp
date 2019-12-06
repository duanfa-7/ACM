
#include<stdio.h>
#include<math.h>
#include<vector> 
#include<string.h>
#include<algorithm>
#define ll long lonh 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N  = 505;
struct node
{
	int x,y;
	node()
	{
		
	};
	node(int p_x, int p_y)
	{
		x = p_x;
		y = p_y;
	}
};
int count1(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2)  + fabs(y1 - y2);
} 
node aux[N * N];
int main()
{
	int data[N][N];
	int res[N][N];
	int n,m;
	scanf("%d %d", &n,&m);
	int len = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d",&data[i][j]);
			if(data[i][j] == 1)
			{
				aux[len++] = node(i,j);
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(data[i][j] == 1)
			{
				res[i][j] = 0;
			}
			else
			{
				int ans = 0x3f3f3f3f;
				for(int k = 0; k < len; k++)
				{
					ans = min(ans,count1(i,j,aux[k].x,aux[k].y));
				}
				res[i][j] = ans;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	return 0;
}
