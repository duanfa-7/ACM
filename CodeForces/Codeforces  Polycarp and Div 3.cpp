#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	string s1;
	while(cin >> s1)
	{
		long long int sum = 0 , ret = 0 ,ans = 0;
		for(int i = 0 ; i < s1.length() ; i++)
		{
			if((s1[i]-'0') % 3 == 0)
			{
			//	printf("s1[%d] = %d\n" , i , s1[i]-'0');
				ans++;
				sum = ret = 0;
			}
			else
			{
				sum = sum + (s1[i]-'0');
				ret++;
				if(sum % 3 == 0 || ret == 3)
				{
				//	printf("sum = %d\n" , sum);
					ans++;sum = ret = 0;
				}
				
			}
		 } 
		 cout << ans << endl;
	}
	return 0;
 } 
