#include<cstdio>
#include<cstring>
#define N 1000001
#define LL long long
//��Ŀ������ N ������ M ��Ҫ���������֮�Ϳ����� M �� �����Щ����λ��
//1.��ǰ׺��ȡ�࣬N > M-1��ô�ض�����sum[i]=sum[j]
//��ôj+1 ~ i ֮��������Ǵ𰸡�  
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

