#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+7;
//�볲ԭ��--һ������ΪN������A����A��ѡ�����ɸ�����ʹ����Щ���ĺ���N�ı����� 
//���磺N = 8������A������2 5 6 3 18 7 11 19������ѡ2 6����Ϊ2 + 6 = 8����8�ı�����
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

