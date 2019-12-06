#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#define ll long long
using namespace std;
ll ExEuclid(ll a , ll b , ll &x , ll &y)
{
	if(b == 0)
	{
		x = 1;y = 0;
		return a;
	}
	ll tx , ty;
	ll d = ExEuclid(b , a%b , tx , ty);
	x = ty;
	y = tx - (a/b)*ty;
	return d ;
}
int main()
{
	ll t , a1 , b1 , a2 , b2 , x , xxx ,y  , k1;
	ll A , B , K;
	int flag;
	while(~scanf("%lld" , &t))
	{
		flag = 0;
		t--;
		scanf("%lld %lld" , &a1 , &b1);
		while(t--)
		{
			scanf("%lld %lld" , &a2 , &b2);
			A = a1 ; B = a2;  K = b2-b1;
			ll d = ExEuclid(A , B ,x , y);
			if(K % d != 0) 
			{
				flag = 1;
			}
		
				x = K / d * x;
				ll t = B / d;
				ll xx = (x % t + t) % t;
				b1 = a1 * xx + b1;
				a1 = A / d * B;
				
		}
		if(flag == 1)
		{
			printf("-1\n");
		 } 
		 else
		 {
		 	printf("%lld\n" , b1);
		 }
	
	}
	
	return 0;
 } 
