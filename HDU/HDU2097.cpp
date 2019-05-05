#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n ;
	while(~scanf("%d" , &n) && n)
	{ 
	int ans = 0 , op = 0 ,ret = 0;
		int t = n , w = n , ii = n;
		while(n)//Ê®½øÖÆ 
		{
			ans += n%10;
			n /= 10;
		}
	//	printf("ans = %d\n" , ans);
		while(t)
		{
			ret += t%16;
			t /= 16; 
		}
	//		printf("ans = %d\n" , ret);
		while(w)
		{
			op += w % 12;
			w /= 12;
		}
	//		printf("ans = %d\n" , op);
		if(ans == ret && ret == op)
		{
			printf("%d is a Sky Number.\n" , ii);
		}
		else
		{
			printf("%d is not a Sky Number.\n" , ii);
		}
	}
	return 0;
}
