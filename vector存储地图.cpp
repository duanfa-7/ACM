#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define N 10000
struct node
{
	int to;
	int cost;
};
vector<node>V[N];
int n , m , temp1;
int main()
{
	scanf("%d %d" , &n , &m);
	while(m--)
	{
		node e;
		scanf("%d %d %d" , &temp1 , &e.to , &e.cost);
		V[temp1].push_back(e);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j < V[i].size() ; j++)
		{
			node e = V[i][j];
			printf("from %d to %d , the cost is %d\n" , i , e.to , e.cost);
		}
	}
	return 0;
}
