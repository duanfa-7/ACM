#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int qpow(int a , int b , int mod)
{
	int answer = 1;
	while(b)
	{
		if(b % 2 == 1)
		{
			answer = (answer % mod * a % mod) % mod;
		}
		b /= 2;
		a = (a % mod * a % mod) % mod;
	}
	return a;
}
int main()
{
	string str , str1;
	int a1 , e1;
	cin >> str;
	int t;
	int s = 0 ,b[10000] , num[10000];
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		cin >> num[i];
	}
	int book = 0  , ans = 0;
	for(int i = 0 ; i < str.length() ; i+=book)
	{
		a1 = 1 ; e1 = 1;
		int cnt = 0;
		if(str[i] == '+' || str[i] == '-')
		{
			str1 = str.substr(book , i-1);
			book = i-1;
		}
		for(int j = 0 ; j < str1.length() ; j++)
		{
			if(str1[j] == 'x')break;
			else
			{
				b[cnt++] = (str1[j] - '0');
			}
		}
		for(int j = cnt-1 ; j >= 0 ; j--)
		{
			a1 = b[j] * pow(10 , j);
		}
		cnt = 0;
		for(int j = str1.length()-1 ; j >= 0 ; j--)
		{
			if(str1[j] == '^')break;
			else
			{
				b[cnt++] = (str1[j] - '0');
			}
		}
		for(int j = 0 ; j < cnt ; j++)
		{
			e1 = b[j] * pow(10 , j);
		}
		for(int k = 0 ; k < t ; k++)
		{
			ans = (ans % MOD + qpow(num[k] , e1 , MOD) % MOD) %MOD;
		}
		ans = ans * a1 % MOD;  
	}
	cout << ans << endl;
	return 0;
}
