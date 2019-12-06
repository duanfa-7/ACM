#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 2e5 + 5;
int father[N],weight[N];
int n,m;
void init(int a, int b, int c)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
		weight[i] = 0;
	}
}

int find(int x)
{
	if(x != father[x])
	{
		int temp = father[x];//存当前父节点 
		father[x] = find(father[x]);//最终节点 
		weight[x] =(weight[x]+ weight[temp]+2)%2;//当前权值加父节点权值 
	}
	return father[x];
}
void merge(int x, int y, int w)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		father[fx] = fy;
		weight[fx] = (w + weight[y] - weight[x]+2)%2;
	}
}
int main()
{
	int T , n , m , x , y;
	char ch[5];
	
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d %d" , &n , &m);
		init(1 , n , 0);
		while(m--)
		{
			scanf("%s %d %d" , &ch , &x , &y);
			if(ch[0] == 'A')
			{
				if(find(x) != find(y))
				{
					printf("Not sure yet.\n");
				}
				else
				{
					if(weight[x] == weight[y])
					{
						printf("In the same gang.\n");
					}
					else
					{
						printf("In different gangs.\n");
					}
				}
			}
			else
			{
				merge(x , y , 1);
			}
		}
	 } 
	return 0;
}

