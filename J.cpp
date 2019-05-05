#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int maxn = 1e5+10;
bool vis[maxn] = {0};
int prime[maxn];
int ret;
void IsPrime()
{
	ret = 0;
	vis[1] = 1;
	for(int i = 2 ; i <= maxn ; i++)
	{
		if(vis[i] == 0)
		{
			prime[ret++] = i;
			for(int j = 2 ; j * i < maxn ; j++)
			{
				vis[i*j] = 1;
			}
		}
	}
}
signed main()
{
	int t , ans;
	ll n;
	IsPrime();
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		cin >> n;
		int sum = 0 ;
		int flag = 0;
		if(n < 0)
		{
			n = -n;
			flag = 1;
		}
		for(int i = 0 ; i < ret ; i++)
		{
			if(n % prime[i] == 0)
			{
				ans = 0;
				while(n % prime[i] == 0)
				{
					ans++;
					n /= prime[i];
				}
				if(sum == 0)
				{
					sum = ans;
				}
				else
				{
					sum = __gcd(sum , ans);
				}	
			}
		}
		if(n > 1)
		{
			sum = 1;
		}
		if(flag == 1)
		{
			while(sum % 2 == 0)
			{
				sum = sum/2;
			}
		}
		printf("Case %lld: %lld\n" , k , sum);
	}
	return 0;
 } 
