#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5+8;
int a[maxn];
int main()
{
    int n , k;
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &a[i]);
    }
    sort(a+1 , a+1+n);
    int mid = n/2+1;
    ll t = a[mid];
    for(int i = mid ; i < n ; i++)
    {
      if(a[i+1] > a[i])
      {
        if((ll)k <= (ll)(i+1-mid)*(a[i+1]-a[i]) && k > 0)
        {
          t += k/(i+1-mid);
          k = 0;
          break;
        }
        else
        {
          t += (a[i+1]-a[i]);
          k -= (i+1-mid)*(a[i+1]-a[i]);
        } 
      }
    }
    if(k > 0)
    {
        t+= k/(n-mid+1);
    }
    printf("%lld\n" , t);
return 0;
}
/*
15 239017
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1000000000
*/