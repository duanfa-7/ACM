#include<bits/stdc++.h>
using namespace std;
const int maxn1 = 105;
const int maxn2 = 1010;
const int Min = -0x7f7f7f7f;
int dp[maxn1][maxn2];
struct Res
{
    int va;//��ֵ 
    int time;//ʱ�� 
}res[maxn1];
int main()
{
    int n,m,l;//��������� �� �̵��������� �� ������ʱ�� 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&l);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&res[i].time,&res[i].va);
        for(int i=0;i<=m;i++)
            for(int j=0;j<=l;j++)//��ʼ�� 
                dp[i][j] = Min;
        for(int i=0;i<=l;i++)
            dp[0][i] = 0;
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--)//���԰����µĶ�άѭ������0-1����������ڲ�ѭ��
                for(int k=l;k>=res[i].time;k--)
                    dp[j][k] = max(dp[j][k],dp[j-1][k-res[i].time]+res[i].va);

        if(dp[m][l] < 0)
            printf("0\n");
        else
            printf("%d\n",dp[m][l]);
    }
}

