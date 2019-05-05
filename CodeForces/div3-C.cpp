#include <bits/stdc++.h>
const int maxn = 2e5+8;
using namespace std;
int a[maxn] , b[maxn] , c[maxn];
int main()
{
	int n , ans = 0 , res = 1;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a+1 , a+1+n);
	for(int i = 2 ; i <= n ; i++)
	{
		b[i] = a[i]- a[i-1];
	}
	for(int i = 2 ; i <= n ; i++)
	{
		if(b[i] > 5)
		{
		//	ans = max(ans , res);
			res = 0;
			continue;
		}
		res++;
		ans = max(ans , res);
	}
	cout << ans << endl;
	return 0;
}
