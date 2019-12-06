#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL ExEuclid(LL a , LL b , LL &x , LL &y)
{
	if(b == 0)
	{
		x = 1;y = 0;
		return a;
	}
	LL tx , ty;
	LL d = ExEuclid(b , a%b , tx , ty);
	x = ty;
	y = tx - (a/b)*ty;
	return d ;
}
int main()
{
	ll A , B , K ;
	ll a , b , c , x , y;
	while(~scanf("%lld %lld %lld" , &a , &b , &c) &&(a+b+c))
	{
		ll d = ExEculid(a , b , x , y);
		x = x * K / d;
		ll t = b / d;
		ll xx = (x % t + t) % t;
		y = (K - a * x)/b;
		if(y < 0) y = -y;
		A = b ; B = a ; K = c;
		ll r = ExEculid(A, B , tx , ty);
		tx = tx * K / r;
		ll t1 = B / d;
		ll xx1 = (tx % t1 + t1) % t1;
		ty = (K - A * tx)/B;
		if(ty < 0) ty = -ty;
		if(x + y > tx + ty)
		{
			printf("%lld %lld\n" , xx1 , ty);
		 } 
		 else
		 {
		 	printf("%lld %lld\n" , xx , y);
		 }
	 } 
	return 0;
}
