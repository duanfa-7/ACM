#include <stdio.h>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s1;
	while(cin >> s1)
	{
		 int ans = 0;
		for(int i = 0 ; i < s1.length(); i++)
		{
			if((s1[i]-'0') % 3 == 0) 
			{
				ans++;
				s1[i] = '#';
			}
			else
			{
				s1[i] = (s1[i]-'0') % 3 + '0';
			}	
				if(i >= 2 && s1[i] == '1' && s1[i-1] == '1' && s1[i-2] == '1') ans++ ; s1[i] = s1[i-1] = s1[i-2] = '#'; 
				if(i >= 2 && s1[i] == '2' && s1[i-1] == '2' && s1[i-2] == '2') ans++ ; s1[i] = s1[i-1] = s1[i-2] = '#'; 
				if(i >= 1 && s1[i] == '2' && s1[i-1] == '1')ans++ ; s1[i] = s1[i-1] = '#';
				if(i >= 1 && s1[i] == '1' && s1[i-1] == '2')ans++ ; s1[i] = s1[i-1] = '#';
			
		}
	cout << ans << endl;
	}
	return 0;
}
