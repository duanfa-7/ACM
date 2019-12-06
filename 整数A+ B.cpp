#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int sum;
bool lalala(string a)
{
	int sum = 0;
	int l = a.length();
	if(l > 4)return 0;
	for(int i = 0 ; i < l ; i++)
	{
		if(a[i] <= '9' && a[i] >= '0')
		{
			sum = sum * 10 + a[i]-'0';
			return 1;
		}
		return 0;
	}
	if(sum > 1000)return 0;
	if(sum == 0)return 0;
	return 1; 
}
int fun(string b)
{
	int sum = 0;
	int l1 = b.length();
	if(lalala(b))
	{
		for(int i = 0 ; i < l1 ; i++)
		{
			sum = sum*10 + b[i]-'0';
		}
		return sum;
	}
}
int main()
{
	int n = 2 ;
	int x = 0;
	int flag = 0;
	
	while(n--)
	{
		string a;
		int flag = 0 ;
		cin >> a;
		cout << "a = " << a;
		if(lalala(a))
		{
			printf("sum = %d" , sum);
		}
		else
		{
			flag = 1;
			printf("?");
		}
		if(n != 0)
		{
			printf(" + ");
		}
		
	}
	if(flag == 1)
	{
		printf(" = ?");
	}
	printf(" = %d" , x);
	
	return 0;
}
