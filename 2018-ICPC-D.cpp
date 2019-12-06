#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t ;
	double n , m;
	scanf("%d" , &t);
	for(int i = 1 ; i <= t ; i++)
	{
		cin >> n >> m;
		double ans1 , ans2;
		if(n == 1) ans1 = 1;
		else ans1 = 0.5;
		ans2 = (m+1)/(2*m);
		printf("Case #%d: %.6f %.6f\n" , i , ans1 , ans2);
	}	
	return 0;
} 