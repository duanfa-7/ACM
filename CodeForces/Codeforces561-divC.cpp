#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5+8;
int a[maxn] , b[maxn];
int main()
{
    int n;
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &a[i]);
        a[i] = abs(a[i]);
    }
    sort(a , a+n);
    ll ans = 0;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int count = lower_bound(a , a+n , 2*a[i]) - a;
        if(a[count] > 2*a[i])
        {
            count = count-i-1;
        }
        else
        {
            while(a[count] == 2*a[i])
            {
                count++;
            }
           count = count-i-1;
        }
        ans += (ll)count;
    }
    cout << ans << endl;
    return 0;
}  