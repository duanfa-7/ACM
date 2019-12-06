#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t , p;
	double ans = 999999;
	double a , b , x;
	cin >> t;
	cin >> a >> b;
	for(int i = 1 ; i <= t ; i++)
	{	
		cin >> x;
		if(abs(a-x*0.006 - b) <= ans)
		{
			ans = abs(a-x*0.006 - b);
			p = i;
		}
	 } 
	 cout << p << endl;
	return 0;
 } 
