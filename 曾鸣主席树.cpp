#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
vector<int>dp,a;
int main()
{
	int n;cin>>n;
	dp.resize(n+10);
	a.resize(n+10);
	for(int i = 0; i < n ; i++) {
		cin>>a[i];
	}
	a[n] = -1;
	int MAX = 0 , i = 0 , tmp = 1;
	for(int i = 1; i <= n ; i++){
		if(a[i-1] < a[i]) {
			tmp ++;
		}
		else MAX = max(MAX,tmp) , tmp = 1;
	}
	cout<<MAX<<endl;
}