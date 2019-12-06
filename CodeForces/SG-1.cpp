#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
#define NINF -INF-1
#define ll long long
#define pi acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);
#define lson rt<<1
#define rson rt<<1|1
#define Lson l,mid
#define Rson mid+1,r
const ll MAXN=1e7+7;
int f[MAXN],sg[MAXN],mex[60];
int a[MAXN];
void get_sg(int a)
{
    mem(mex,0);
    for(int i=19;i>=0;--i)
    {
        if(a&(1<<i)) 
        {
            for(int j=i-1;j>=0;--j)
            {
                if(!(a&(1<<j)))
                {
                    mex[sg[a^(1<<i)^(1<<j)]]=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i <=100;++i)
        if(!mex[i])
        {
            sg[a]=i;
            printf("a = %d i = %d\n" , a , i);
            break;
        }
}
int main()
{
    for(int i=1;i<(1<<8);++i)
        get_sg(i);
    int t;
    scanf("%d",&t);
    // for(int i = 1 ; i <= 20 ; i++)
    // {
    //     printf("sg[%d] = %d\n" , i , sg[i]);
    // }
    while(t--)
    {
        int n,sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            int m;
            scanf("%d",&m);
            a[i]=0;
            for(int j=0;j<m;++j)
            {
                int vis;
                scanf("%d",&vis);
                a[i]^=(1<<(20-vis));
            }
            sum^=sg[a[i]];
        }
        printf(sum?"YES\n":"NO\n");
    }
}
