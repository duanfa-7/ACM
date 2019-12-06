#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+8;
ll ans1 , ans2;
ll a[maxn];
int main()
{
    int n ;
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ans1 = 0; ans2 = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a+1 , a+n+1);
    for(int i = 1 ; i <= n ; i++)
    {
        if(i <= n/2)ans1+=a[i];
        else ans2+=a[i];
    }
    ll ans = ans1*ans1+ans2*ans2;
    cout << ans << endl;
    return 0;
}