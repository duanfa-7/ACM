#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
const int maxn = 2e5+8;
using namespace std;
double a[maxn] , b[maxn] , x[maxn] , y[maxn];
int main()
{
	int n; 
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> x[i];	
	}
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> y[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(x[i] == 0)
		{
			a[i] = INF;
		}
		else
		{
			a[i] = -(y[i]/x[i]);
		}
	}
	sort(a+1 , a+1+n);
//	for(int i = 1 ; i <= n ; i++)
//	{
//		cout <<a[i]<<" "; 
//	}
//	cout << endl;
	int ans = 0 ,res = 1;
	for(int i = 1 ; i < n ; i++)
	{	
		if(a[i] == INF) continue;
		if(a[i+1] == a[i] )
		{
			res++;
			ans = max(ans , res);
		}
	
	}
	if(ans == 0)
	{
		cout <<"0"<<endl;
	}
	else
	{
		cout << ans << endl;
	}
	return 0;
}
