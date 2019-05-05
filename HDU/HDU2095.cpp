#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n ,a ,ans;
	while(~scanf("%d" , &n) && n)
	{
		ans = 0;
		while(n--)
		{
			scanf("%d" , &a);
			ans ^= a;
		}
		printf("%d\n" , ans);
	}
	return 0;
}
