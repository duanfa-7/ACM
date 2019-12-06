#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
	char str[10000];
	int t;
	char ch;
	vector<char>V;
	cin >> t;
	while(t--)
	{
		gets(str);
		int ans = 0;
		for(int i = 0 ; i < strlen(str) ; i++)
		{
			V.push_back(str[i]);
		}
		ch = V[0];
		cout << ch << endl;
		V.erase(V.begin());
	 
		for(int i = 0 ; i < V.size() ; i++)
		{
			
		}
	}
	return 0;
}
