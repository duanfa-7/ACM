#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1008000;
int prime[maxn] , k , vis[maxn];
void Prime()
{
	 k = 0;
	memset(vis , 0 , sizeof(vis));
	for(int i = 2 ; i < maxn ; i++)
	{
		if(!vis[i])
		{
			prime[k++] = i;
			for(int j = 2 ; i * j < maxn ; j++)
			{
				vis[i*j] = 1;
			} 
		}
	}
}
ll solve(ll n)//KËØÊý¸öÊý 
{
	ll sum = 1;
	for(int i = 0 ; i < k && prime[i] * prime[i] <= n ; i++)
	{
		if(n % prime[i] == 0)
		{
			int ans = 0;
			while(n % prime[i] == 0)
			{
				ans++;
				n /= prime[i];
			}
			sum *= (1+ans);
		}
		
	}
	if(n > 1)
	sum *= 2;
	return sum;
}
int main()
{
	int T  , t =  1;
	
	cin >> T;
	Prime();
	while(T--)
	{
		ll a , b;
		cin >> a >> b;
		if(a <= b* b)
		{
			printf("Case %d: 0\n" , t++);
			continue;
		}
		ll num = solve(a);
		num /= 2;
		for(int i = 1 ; i < b ; i++)
		{
			if(a % i == 0)
			{
				num--;
			}
		}
		printf("Case %d: %lld\n" , t++ , num);
	}
	return 0;
 } 

