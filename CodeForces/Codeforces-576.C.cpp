#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 4e5+8;
int a[maxn] , sum[maxn];
map<int , int>M;
vector< pair<int,int> >V;
bool cmp(const pair<int,int> a , const pair<int,int> b)
{
    return a.first < b.first;
}
int main()
{
    int n , I ;
    int ans = INF , cnt = 0;
    scanf("%d %d" , &n , &I);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &a[i]);
        if(!M.count(a[i]))
        {
            cnt++;//不同数
        }
        M[a[i]]++;//每个数的数量
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(M[a[i]] != 0)
        {
            V.push_back(make_pair(a[i] , M[a[i]]));
            M[a[i]] = 0;
        }
     
    }
    sort(V.begin() , V.end() , cmp);
 //   sum[1] = V[0].second;
    int vsi = V.size();
    // for(int i = 0 ; i < vsi ; i++)
    // {
    //     cout << "1:" << V[i].first <<"2:" << V[i].second << endl;
    // }
    sum[0] = 0;
    for(int i = 0 ; i < vsi ; i++)
    {
       sum[i+1] = sum[i] + V[i].second;
    }
    int opp = 8*I/n;
    if(opp > 33) opp = 33;
    ll K = pow(2,opp);
    if(opp >= 20)
    {
        printf("0\n");
    }
    else
    {
        if(cnt <= K )
        {
            printf("0\n");
        }
        else
        {
            for(int j = 1 ; j < n-K+1 ; j++)
            {
                ans = min(ans , n-(sum[j+K-1] - sum[j-1]));
            }
            printf("%d\n" , ans);
       }
   }
    return 0;
}