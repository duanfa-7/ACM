#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
	int n , m , x ,ans = 0;
	vector<int>V;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
	{
		cin >> x;
		
		auto it = find(V.begin() , V.end() , x);	
		if(it != V.end())
		{
			ans++;
			continue;
		}
		if((int)V.size() == n)
		{
			V.erase(V.begin() , V.begin()+1);
		}
		V.push_back(x);
	}
	cout << m-ans << endl;
	return 0;
}
