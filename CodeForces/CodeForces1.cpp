#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<char , int> M;
	string s1;
	int flag = 0;
	M['a'] = 1;M['e'] = 1;M['i'] = 1;M['o'] = 1;M['u'] = 1;
	cin >> s1;
	for(int i = 0 ; i < s1.length() ; i++)
	{
		if(s1[i] == 'n')
		{
			continue;
		}
		else
		{
			if(M[s1[i]] != 1 && M[s1[i+1]] != 1)
			{
			flag = 1;
				break;
			}
		}
	}
	if(flag== 1)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	return 0;
}
