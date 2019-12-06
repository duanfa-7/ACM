#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e5;
using namespace std;
bool vis[maxn];
int main()
{
	ll n , p , w , d;
	ll x = 0 , y = 0 ;
	int flag = 0;
	scanf("%lld %lld %lld %lld" , &n , &p , &w , &d);
	 for(ll i = 0 ; i*d <= p ; i++)//记录平局的次数
	{
		if((p-i*d)%w == 0)
		{
			y = i;
			x = (p-i*d)/w;
			flag = 1;
			break;
		}
		if(vis[(p-i*d)%w] == 0)//循环节跳出 ， 节省时间
		{
			vis[(p-i*d)%w] = 1;
		}
		else
		{
			break;
		}
	}
	if(flag && x+y<=n) printf("%lld %lld %lld\n" , x , y , n-x-y);
	else printf("-1\n");
	return 0;
}