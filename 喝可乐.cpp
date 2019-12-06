#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int maxn = 106;
int vis[maxn][maxn][maxn];
bool check(int a , int b , int c)
{
	if((a == 0 && b == c )||(b == 0 && a == c)  || (c == 0 && a == b))return true;
	return false;
}
struct node 
{
	int x , y , z;
	int step;
};
int a , b , c;
int bfs()
{
	node now , next;
	memset(vis , 0 , sizeof(vis));
	now.x = a;
	now.y = 0;
	now.z = 0;
	now.step = 0;
	vis[now.x][now.y][now.z] = 1;
	queue<node> Q;
	Q.push(now);
	if(now.x % 2 == 1)return 0;
	while(!Q.empty())
	{
		now = Q.front();
//	printf("x = %d y = %d z = %d s = %d\n" , now.x , now.y , now.z , now.step);
		Q.pop();
		if(check(now.x , now.y , now.z))
		{
			printf("%d\n" , now.step);
			return 1;
		}
		int num;
		if(now.x != 0)//x杯里有饮料 
		{
			if(b - now.y > 0) //B杯还有剩余 
			{
				num = b-now.y; 
				next.step = now.step + 1;
				next.z = now.z;
				if(now.x > num)
				{
					next.x = now.x - num;
					next.y = b;
				}
				else
				{
					next.x = 0;
					next.y = now.y + now.x;
				}
				if(!vis[next.x][next.y][next.z])
				{
					vis[next.x][next.y][next.z] = 1;
				//	printf("x = %d y = %d z = %d" , next.x , next.y , next.z);
					Q.push(next);
				}
			}
			if(c - now.z > 0) //c杯还有剩余 
			{
				num = c-now.z; 
				next.step = now.step + 1;
				next.y = now.y;
				if(now.x > num)
				{
					next.x = now.x - num;
					next.z = c;
				}
				else
				{
					next.x = 0;
					next.z = now.z + now.x;
				}
				if(!vis[next.x][next.y][next.z])
				{
					vis[next.x][next.y][next.z] = 1;
				//	printf("x = %d y = %d z = %d" , next.x , next.y , next.z);
					Q.push(next);
				}
			}
		}
		
			if(now.y != 0)//y杯有饮料 
			{
				if(a - now.x > 0)
				{
					num = a - now.x;
					next.z = now.z;
					next.step = now.step + 1;
					if(now.y > num)
					{
						next.x = a;
						next.y = now.y-num; 
					}
					else
					{
						next.y = 0;
						next.x = now.x + now.y;
					}
					if(!vis[next.x][next.y][next.z])
					{
							vis[next.x][next.y][next.z] = 1; 
					//	printf("x = %d y = %d z = %d" , next.x , next.y , next.z);
						Q.push(next);
					}
				}
			if(c - now.z > 0)
				{
					num = c - now.z;
					next.x = now.x;
					next.step = now.step + 1;
					if(now.y > num)
					{
						next.z = c;
						next.y = now.y-num; 
					}
					else
					{
						next.y = 0;
						next.z = now.z + now.y;
					}
						if(!vis[next.x][next.y][next.z])
					{
							vis[next.x][next.y][next.z] = 1;
					//	printf("x = %d y = %d z = %d" , next.x , next.y , next.z);
						Q.push(next);
					}
				} 
			}
		if(now.z != 0)//z杯有饮料 
		{
			if(a - now.x > 0)
			{
				num = a - now.x;
				next.step = now.step + 1;
				next.y = now.y;
				if(now.z > num)
				{
					next.z = now.z - num;
					next.x = a;
				}
				else
				{
					next.z = 0;
					next.x = now.z + now.x; 
				}
				if(!vis[next.x][next.y][next.z])
				{
					vis[next.x][next.y][next.z] = 1;
				//	printf("x = %d y = %d z = %d" , next.x , next.y , next.z);
					Q.push(next);
				}
			}
				if(b - now.y > 0)
			{
				num = b - now.y;
				next.step = now.step + 1;
				next.x = now.x;
				if(now.z > num)
				{
					next.z = now.z - num;
					next.y = b;
				}
				else
				{
					next.z = 0;
					next.y = now.z + now.y; 
				}
				if(!vis[next.x][next.y][next.z])
				{
					vis[next.x][next.y][next.z] = 1;
				//	printf("x = %d y = %d z = %d" , next.x , next.y , next.z);
					Q.push(next);
				}
			}
		}
			
	 } 
	 return 0;
}
int main()
{
	while(~scanf("%d %d %d" , &a , &b , &c) && (a+b+c))
	{
		int ans = bfs();
	//	printf("ans = %d\n" , ans);
		if(ans == 0)
		{
			printf("NO\n");
		}
	}
	
	return 0;
}
