#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+8;
int a[maxn] , sum1[maxn] , sum[maxn];
int main()
{
	int t , n;
	scanf("%d" , &t);
	while(t--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d" , &a[i]);
		}
		sum[1] = a[1];
		for(int i = 2 ; i < n ; i++)
		{
			sum[i] = __gcd(sum[i-1] , a[i]); 
		}
		sum1[n] = a[n];
		for(int i = n-1 ; i >= 1 ; i--)
		{
			sum1[i] = __gcd(sum1[i+1], a[i]);
		}
		int ans;
		ans = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			ans = max(ans , __gcd(sum[i-1] , sum1[i+1]));
		}
		printf("%d\n" , ans);
	}
	return 0;
}