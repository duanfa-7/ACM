#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
int vis[maxn];
int main()
{
	int n , x , cnt;
	scanf("%d %d" , &n , &x);
	cnt = (1 << n);
	for(int i = 0 ; i < cnt ; i++)
	{
		if(!vis[i])
		{
			vis[i^x] = 1;
		}
	}
	vector<int>V;
	int ans = 0;
	for(int i = 1 ; i < cnt ; i++)
	{
		if(!vis[i])
		{
			ans++;
			V.push_back(i);
		}
	}
	cout << ans << endl;
	int op = 0;
	for(int i = 0 ; i < V.size() ; i++)
	{
		cout << (op^V[i]) << " ";
		op = V[i];
	}
	cout << endl;
	return 0;
}