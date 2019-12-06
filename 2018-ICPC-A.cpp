aaa
#include <bits/stdc++.h>
#define ll long long
#define uu unsigned int
using namespace std;
int n , p , q , m;
uu SA , SB , SC;
stack <ll> s;
void PUSH(ll x)
{
	if(s.empty()) s.push(x);
    else s.push(max(x , s.top()));
} 
void POP()
{
   if(!s.empty()) s.pop();
}
uu rng61()
{
    uu t;
    SA^=SA<<16;
    SA^=SA>>5;
    SA^=SA<<1;
    t=SA,SA=SB,SB=SC,SC^=t^SA;
    return SC;
}
ll gen()
{
    ll ans = 0;
	scanf("%d %d %d %u %u %u" , &n , &p , &q , &SA , &SB , &SC);
    for(int i = 1 ; i <= n ; i++)
    {
        if(rng61( )% (p+q) < p)
        {
            PUSH(rng61() % m + 1);
        }
        else
        {
            POP();
        }
        ans ^= (i*s.top());
    }
    return ans;
}
int main()
{
	int t;
    scanf("%d",&t);
    for(int i = 1 ; i <= t ; i++)
    {
        while(!s.empty())s.pop();
        printf("Case #%d: %lld" , i  , gen());
    }
	return 0;
 } 
