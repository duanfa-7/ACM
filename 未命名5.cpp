// 18位素数：154590409516822759
// 19位素数：2305843009213693951 (梅森素数)
// 19位素数：4384957924686954497
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL prime[6] = {2, 3, 5, 233, 331};
LL qmul(LL x, LL y, LL mod) // 乘法防止溢出， 如果p * p不爆LL的话可以直接乘； O(1)乘法或者转化成二进制加法
{ 
    return (x * y - (long long)(x / (long double)mod * y + 1e-3) *mod + mod) % mod;
}
LL qpow(LL a, LL n, LL mod) {
    LL ret = 1;
    while(n) {
        if(n & 1) ret = qmul(ret, a, mod);
        a = qmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}
bool Miller_Rabin(LL p) {
    if(p < 2) return 0;
    if(p != 2 && p % 2 == 0) return 0;
    LL s = p - 1;
    while(! (s & 1)) s >>= 1;
    for(int i = 0; i < 5; ++i) {
        if(p == prime[i]) return 1;
        LL t = s, m = qpow(prime[i], s, p);
        while(t != p - 1 && m != 1 && m != p - 1) {
            m = qmul(m, m, p);
            t <<= 1;
        }
        if(m != p - 1 && !(t & 1)) return 0;
    }
    return 1;
}
int main()
{
	LL n;
	scanf("%lld" , &n);
	if(Miller_Rabin(n))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
 } 
