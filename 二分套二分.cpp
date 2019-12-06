#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
int data[maxn];
int n;
int count1(int key)//二分找个数 
{
	int res = 0 , sum = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		res = upper_bound(data+1 , data+1+n , key+data[i])-(data+1);
		if(res != n+1)
		{
			sum += (n - res);
		}
	}
	return sum;
}
int count2(int a , int b , int k)//二分找key 
{
	while(a < b)
	{
		int m = (a+b)/2;
		int tmp = count1(m);
		if(tmp <= k)
		{
			b = m;
		}
		else
		{
			a = m+1;
		}
	}
	return a;
}
int main()
{
	while(~scanf("%d" , &n))
	{
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d" , &data[i]);
		} 
		sort(data+1 , data+1+n);
		
		int num2 = (ll)n*(ll)(n-1)/(ll)2;
		int num1 = (num2+1)/2;
		int ans = count2(1 , 1e9 , (num2-num1));
		printf("%d\n" , ans);
	}
	return 0;
 } 
