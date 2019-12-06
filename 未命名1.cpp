#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+7;
//鸽巢原理--一个长度为N的数组A，从A中选出若干个数，使得这些数的和是N的倍数。 
//例如：N = 8，数组A包括：2 5 6 3 18 7 11 19，可以选2 6，因为2 + 6 = 8，是8的倍数。
int vis[maxn];
int a[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int sp=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(vis,0,sizeof(vis));

        int sum=0,l=0,r=0;
        for(int i=1;i<=n;i++)
        {
            sum=(sum+a[i]%n)%n;
            if(sum==0)
            {
                l=1;
                r=i;
                break;
            }
            if(vis[sum])
            {
                l=vis[sum]+1;
                r=i;
                break;
            }
            vis[sum]=i;
        }
        printf("%d\n",r-l+1);
        for(int i=l;i<=r;i++)
        {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}

