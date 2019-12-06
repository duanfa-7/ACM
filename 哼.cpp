#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , x;
	string str;
	cin >> n;
	int m = n;
	for(int i = 0 ; i < n+1 ; i++)
	{
		cin >> x;
		if(x == 0) {m--;continue;}
		if(i == n)
		{
			if(x > 0)
			{
				str += "+";
				str += to_string(x);
			}
			else str += to_string(x);
		} 
		if(i != 0)
		{
			if((x == 1 || x == -1) && m != 0 )
			{
				if(m == 1)
				{
					if(x > 0) str += "+x"; 
					else str += "-x";
				}
				else
				{
					if(x > 0)
					{
						str += "+x^";
						str += to_string(m);
					}
					else
					{
						str += "-x^";
						str += to_string(m);
					}
				}
			}
			if((x > 1 || x < -1) && m != 0)
			{
				if(m == 1)
				{
					if(x > 1)
					{
						str += "+";
						str += to_string(x);
						str += "x";
					}
					else
					{
						str += to_string(x);
						str += 'x';
					}
				}
				else
				{
					if(x > 1)
					{
						str += "+";
						str += to_string(x);
						str += "x^";
						str += to_string(m);
					}
					else
					{
						str += to_string(x);
						str += "x^";
						str += to_string(m);
					}
				}
			}
		}
		else
		{
			if((x == 1 || x == -1) && m != 0)
			{
				if(m == 1)
				{
					if(x > 0) str += "x";
					else str += "-x";
				}
				else
				{
					if(x > 0)
					{
						str += "x^";
						str += to_string(m);
					}
					else
					{
						str += "-x^";
						str += to_string(m);
					}
				}
			}
			if((x > 1 || x < -1)&& m != 0)
			{
				if(m == 1)
				{
						str += to_string(x);
						str += "x";
				}
				else
				{
					if(x > 1)
					{
						str += to_string(x);
						str += "x^";
						str += to_string(m);
					}
					else
					{
						str += to_string(x);
						str += "x^";
						str += to_string(m);
					}
				}
			}
		}
		m--;
	}
	if(str[0] == '+') for(int i = 1 ; i < str.size() ; i ++) cout<<str[i];
    else cout << str;
	return 0;
}
