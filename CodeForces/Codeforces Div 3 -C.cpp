#include <stdio.h>
#include <iostream>
#include <set>
#include <bits/stdc++.h>
const int maxn = 2e5+8;
using namespace std;
int main()
{
	long long int n, a[maxn] , suml ,sumr , max = -999999;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	int l = 1 , r = n;
	suml = 0;
	sumr = 0;
		while(l <= r)
		{
			if(suml < sumr)
			{
				suml += a[l];
				l++;
			}
			else if( suml > sumr)
			{
				sumr += a[r];
				r--;
			}
			else
			{
				if(sumr > max)
				{
					max = sumr;
				}
				
				suml+=a[l];
				l++;
			}
		}
		if(suml == sumr)
		{
			if(sumr > max)
			{
				max = sumr;
			}
		}
	cout << max << endl;
	return 0;
}
