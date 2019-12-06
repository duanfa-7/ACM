#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long 
#define MOD 1000000009 
int book[1500];
int myc(int n , int r)
{
	long long  sum = 1;
	for(int i = 0 ; i <= r ; i++)
	{
		sum = sum * (n+1-i)/i;
	}
	return sum % MOD;
}
/*long long int fun( long long int x , long long int y)
{
	if(x == y+1)
	{
		return y+1;
	}
	if(x != y+1)
	{
		return x * fun(x-1 , y);
	}
}
	long long int fun1( long long int n)
	{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * fun1(n-1);
	}
}*/

 main() 
{
    int n , m , k ;
	int a[1500];
while(~scanf("%lld %lld %lld" , &n , &m , &k))
{
	memset(book , 0 , sizeof(book));
	memset(a , 0 , sizeof(a));
	int sum = 0 ;
	int max = -1;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%lld" , &a[i]);
			book[a[i]]++;
		//	book[a[i]] = 1;
			if(a[i] > max)
			{
				max = a[i];
			}
		}
		for(int i = 0 ; i < 105 ; i++)
		{
			int ans = 0;
		//	int t = a[i]; 
			int t = i;//这里的 i 指的就是a[i]  
			if(book[i] == 0) continue;
			while(t <= max )
			{	
				if(book[t])
				{
					ans = ans + book[t];	
					book[t] = 0;
				//	printf("ans = %d   " , ans);
				//	printf("t = %d\n" , t);
					t = t + k;
				}
				else
				{
					t = t + k;
				}
			
			}
			sum = (sum + myc(ans , m)) % MOD; 
		//	if(ans >= m)
		//	{
		//		sum += (fun(ans , ans - m)/fun1(m))%1000000009 ;
		//	}
		}
		printf("%lld\n" , sum % MOD);
}
	return 0;
}
/*

20 3 2
2 4 6 8 10 12 14 16 18 19 32 34 38 51 63 72
67  99 89 78
5 3 2  
1 2 3 4 5
5 2 4
3 8 10 11 13 17
5 2 4 
1 1 1 1 1 

*/ 
