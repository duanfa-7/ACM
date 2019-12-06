#include <bits/stdc++.h>
#include <queue>
using namespace std;
int N , M , k , G[505][505] , v[505] , s[505];
priority_queue<int , vector<int> , greater<int> > q;
void topusort()
{
	for(int i = 1 ; i <= N ; i++)
	{
		if(v[i] == 0)
		{
			q.push(i);
		}
	}
	int t;k = 0 ;
	while(!q.empty())
	{
		t = q.top();
		s[k++] = t;
		q.pop();
		for(int i = 1 ; i <= N ; i++)
		{
			if(G[t][i] == 1)
			{
				v[i]--;
				if(v[i] == 0)
				{
					q.push(i);
				}
			}
			
		}
	}
}
int main()
{
	int a , b;
	while(~scanf("%d %d" , &N , &M) && (N+M))
	{
		memset(G , 0 , sizeof(G));
		memset(v , 0 , sizeof(v));
		while(M--)
		{
			scanf("%d %d" , &a , &b);
			if(G[a][b] == 0)
			{
				G[a][b] = 1;
				v[b]++;
			}
		}
		topusort();
		for(int i = 0 ; i < k ; i++)
		{
			if(i != k-1)
			{
				cout << s[i] << " ";
			}
			else
			{
				cout << s[i] << endl; 
			}
		}
		
	}
	return 0;
 } 
