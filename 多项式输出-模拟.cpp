#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	int n , m , x;
	cin >> n;
	m = n;
	for(int i = 1 ; i <= n + 1 ; i++)
	{
		cin >> x;
		if(x == 0)
		{
			m--;
			continue;
		}
		
		if(i == n && m == 1)
		{
			if(x > 0)
			{
				if(n != 1)
				{
					str += '+';
					if(x != 1)
					{
						str += to_string(x);
					}
				}	
				str += 'x';
			}
			else
			{
				if( n != 1)
				{
					if(x != -1)
					{
						str += to_string(x);
					}
				}	
				str += 'x';
			}
			continue;
		}
		if(i == 1 && m != 1)
		{
			if(x == 1)
			{
				str += "x^";
				str += to_string(m);
				m--;
			}
			if(x == -1)
			{
				str += "-x^";
				str += to_string(m);
				m--;
			}
			if(x > 1)
			{
				str += to_string(x);
				str += "x^";
				str += to_string(m);
				m--;
			}
			if(x < -1)
			{
				str += to_string(x);
				str += "x^";
				str += to_string(m);
				m--;
			}
		}
		if(i == n+1)
		{
			if(x > 0)
			{
				str += '+';
				str += to_string(x);
			}
			else
			{
				str += to_string(x);
			}
		}
		if(i > 1 && i < n && m != 1 && m != 0)
		{
			if(x == 1)
			{
				str += "+x^";
				str += to_string(m);
				m--;
			}
			if(x == -1)
			{
				str += "-x^";
				str += to_string(m);
				m--;
			}
			if(x > 1)
			{
				str += '+';
				str += to_string(x);
				str += "x^";
				str += to_string(m);
				m--;
			}
			if(x < -1)
			{
				str += to_string(x);
				str += "x^";
				str += to_string(m);
				m--;
			}
		}
	}
	if(str[0] == '+')
	{
		str.erase(0,1);
	}
	cout << str;
	return 0;
 } 
