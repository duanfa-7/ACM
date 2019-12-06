#include <bits/stdc++.h>
const int maxn = 2e5+8;
int vis[maxn] , d[maxn];
using namespace std;
int main()
{
	int n , k , ans = 0;
	memset(vis , 0 , sizeof(vis));
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> d[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = i+1 ; j <= n ; j++)
		{
			if(vis[i] == 0 && vis[j] == 0 &&(d[i] + d[j]) %k == 0)
			{
				vis[i] = 1;
				vis[j] = 1;
				ans++;
			}
		}
	}
	cout << ans*2 << endl;
	return 0;
}
