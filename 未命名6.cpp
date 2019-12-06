#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 510;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];
int in[maxn];
int vis[maxn];
int ans[maxn];
int cnt;
int n, m;
void Sort()
{
	while(1)
	{
		int pos = INF;
		for(int i = 1; i <= n; i++)
		{
			if(in[i] == 0 && vis[i] == 0)
			{
				pos = i;
				break;
			}
		}
		if(pos == INF) break; 
		vis[pos] = 1;
		ans[cnt++] = pos;	
		for(int i = 1; i <= n; i++)
		{
			if(G[pos][i] == 1 && vis[i] == 0)
			{
				if(in[i] != 0)
				in[i]--;
			}
		}
	}
}

void init()
{
	cnt = 0;
	memset(G, 0, sizeof(G));
	memset(in, 0, sizeof(in));
	memset(vis, 0, sizeof(vis));
}

int main()
{
	int u, v;
	while(cin >> n >> m)
	{
		init(); 
		for(int i = 0; i < m; i++)
		{
			cin >> u >> v;
			in[v]++;
			G[u][v] = 1;
		}
		Sort();
		for(int i = 0; i < cnt; i++)
		{
			cout << ans[i];
			if(i < cnt - 1)
			{
				cout << " ";
			}
			
		}
		cout << endl;
	}
	return 0;
}
