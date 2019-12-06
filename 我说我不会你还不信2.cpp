#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define MOD 1000000009
int book[1500];
int myc(int n,int r)
{
	long long sum = 1;
	for(int i = 1 ; i <= r ; i++)
	{
		sum = sum*(n+1-i)/i;
	}
	return sum%MOD;
}
main() 
{
    int n , m , k ;
	int a[1500];
	while(~scanf("%lld %lld %lld" , &n , &m , &k))
	{
		memset(book,0,sizeof(book));
		memset(a,0,sizeof(a));
		int sum = 0;
		int max = -1;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%lld" , &a[i]);
			book[a[i]]++;//这里是 ++ 
			if(a[i] > max)
			{
				max = a[i];
			}
		}
		for(int i = 0 ; i < 105 ; i++)//桶排序 数组里的i才是我们要的值 不是a[i] 
		{
			int ans = 0;
			int t = i;//*** bug 这里的 i 指的就是a[i] 
			if(book[i] == 0) continue; //***** bug 
			while(t <= max )
			{	
				if(book[t])
				{
					ans = ans+book[t];	
					book[t] = 0;
					t = t + k;
				}
				else
				{
					t = t + k;
				}
			}
		//	if(ans >= m )
			{
				sum= (sum + myc(ans,m))%MOD;//组合数求错了，阶乘求组合数会爆long long   
			}
		}
		printf("%lld\n" , sum%MOD); 
}
	
	return 0;
}

