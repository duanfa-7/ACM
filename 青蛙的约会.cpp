#include<stdio.h>
#include <iostream>
#define ll long long
using namespace std;
ll ExEculid(ll a , ll b , ll &x , ll &y)
{
	if(b == 0)
	{
		y = 0 ; x = 1;
		return a;
	}
	
	ll tx , ty;
	ll d = ExEculid(b , a%b ,tx , ty);
	x = ty;
	y = tx - ( a/b )* ty;
	return d;
 } 
 int main()
 {
 	ll x , y , m , n , l , k1 , k2 ;
 	scanf("%lld %lld %lld %lld %lld" , &x , &y , &m , &n , &l);	
 	ll A = n-m;
 	ll B = l;
	ll K = x-y;
//	if(B < 0)
//	{
//		B = - B;
//		A = - A;
//		K = - K;
//	}
	ll d = ExEculid(A , B , k1 , k2); 
	if(K % d != 0 )
	{
		printf("Impossible\n");
	}
	else
	{ 
		k1 = k1 * K / d;
		ll t = B / d;
//		if(t < 0)
//		{
//			t = - t;
//		}
		ll xx = (k1%t + t) % t ;
		printf("%lld\n" , xx);
	}
 	return 0 ;
 }
