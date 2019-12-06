#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+8;
int a[maxn];
bool vis[maxn];
int main()
{
    int t , n , x;
    scanf("%d" , &t);
    while(t--)
    {
        scanf("%d" ,&n);
        set<int>S;
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d" , &x);
           S.push(x);
        }
        cout << S<<endl;
    }
    return 0;
}