#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	long long int a , b;
	int len;
	string stra , strb;
	while(cin >> stra>>strb)
	{
		a = 0 ;
		b = 0 ;
		len = stra.length();
		for(int i = 0 ; i < len ; i++)
		{
			if(stra[i] != '.')
			{
				a *= 10;
				a += stra[i]-'0';
			}
		}
		len = strb.length();
		for(int i = 0 ; i < len ; i++)
		{
			if(strb[i] != '.')
			{
				b *= 10;
				b+= strb[i] - '0';
			}
		}
		if(a % b == 0)
		{
			cout << "0"<<endl;
		}
		else
		{
			printf("%.9f" , a%b/1000000000.0);
		}
	}
}
