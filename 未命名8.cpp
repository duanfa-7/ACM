#include <bits/stdc++.h>
using namespace std;
const int maxn = 3008;
int vis[maxn];
struct node
{
	int p;
	int c;
}a[maxn];
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i<= n ; i++)
	{
		cin >> a[i].p >> a[i].c;
	}
	return 0;
}
