#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e14+8;
using namespace std; 
int a[666666];
bool book[maxn] = {0};
void shai()
{
	ll cnt = 0;
	for(int i = 2 ; i < sqrt(maxn) ; i++)
	{
		if(book[i] == 0)
		{
			a[cnt++] = i;
			for(int j = 2 ; j * i < maxn ; j++)
			{
				book[i*j] = 1;
			}
		}
	}
}
ll getsum(ll n)
{
	ll sum = 1;
	for(int i = 0 ; i < cnt ; i++)
	{
		if(n % a[i] == 0)
		{
			ll ans = 0;
			while(n % a[i] == 0)
			{
				b[ans++] = a[i];
				n /= a[i];
			}
			for(int j = 0 ; j < ans ; j++)
			{
				
			}
		}
	}
}
int main()
{
	
	return 0;
}
