#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
map<int,int>M;
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	int pos = n;
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] != pos)
		{
			puts("");
			M[a[i]] = 1; 
		}
		else 
		{
			cout<<pos<<" ";
			pos--;
			while(M[pos]) cout<<pos<<" " , pos--;
			puts("");
		}
	}
}
