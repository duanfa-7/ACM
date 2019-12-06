#include<cstdio>
#include<cstring>
#define N 1000001
#define LL long long
//题目：给你 N 个数和 M ，要求任意个数之和可整除 M ， 输出这些数的位置
//1.求前缀和取余，N > M-1那么必定会有sum[i]=sum[j]
//那么j+1 ~ i 之间的数就是答案。  
LL a[N],drawer[N]; 
LL sum[N];
int main()
{
    LL c,n;
    while(scanf("%lld%lld",&c,&n)!=EOF&&c&&n)
    {
        memset(drawer,-1,sizeof(drawer));
        drawer[0]=0;
        sum[0]=0;
        
        for(LL i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        
        for(LL i=1;i<=n;i++)
        {
            if(drawer[sum[i]%c]!=-1)
            {
                for(LL j=drawer[sum[i]%c]+1;j<i;j++)
                    printf("%lld ",j);
                printf("%lld\n",i);
                break;
            }
            drawer[sum[i]%c]=i;
        }
    }
    return 0;
}

