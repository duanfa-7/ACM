#include <stdio.h>
long long  dp[350][350];
int main()
{
long long n , k;
	scanf("%lld %lld" , &n , &k);
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= k ; j++)
		{
			dp[i][j] = 0;
			dp[i][1] = 1;//��I�ֳ�һ�� �� ��һ��
			dp[1][j] = 1;//��1�ֳɲ�����j�� �� һ��
		}
	}
//		for(int i = 0 ; i < n ; i++)
//	{
//		for(int j = 0 ; j < k ; j++)
//		{
//			printf("%d " , dp[i][j]);
//		}
//		printf("\n");
//	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= k ; j++)
		{//i < j ʱ �� �൱�ڽ�i�ֳ�i��
			if(i < j )
			{
				dp[i][j] = dp[i][i];
			}

                        //i==jʱ �� �ֳ����� �� һ����ֻ��1��� ��ֻ��һ�֣�����һ���Ƿֳ�С��j�ݣ���������һ���ǿգ� 
			else if( i == j)
			{
				dp[i][j] = dp[i][j-1] + 1;
			}
			else//i>jʱ ���ֳ�j�ݺ�С��j�ݵ���� 

			{
				dp[i][j] = dp[i][j-1] + dp[i-j][j];
			}
		}
	}
//	for(int i = 0 ; i < n ; i++)
//	{
//		for(int j = 0 ; j < k ; j++)
//		{
//			printf("%d " , dp[i][j]);
//		}
//		printf("\n");
//	}
printf("%lld\n" , dp[n][k]);
	return 0;
}
/*
#include<iostream>
using namespace std;
long long a[400][400];//a[n][k]��ʾ����n���ֳ�k�ݣ�ÿ�ݿ���������ֵ
int main()
{
    long long n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        a[i][1]=1;//��i�ֳ�1�ݣ�ֻ��һ�ַַ�
    }
    for (int j=1;j<=k;j++)
    {
        a[1][j]=1;//��1�ֳ�j����һ��
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
        {
                //��i<jʱ����Ϊ��ʱ���ֳ�i�ݣ�ʵ�����൱�ڽ�i�ֳ�i��
            if(i<j)
                a[i][j]=a[i][i];
                //��i==jʱ�������������һ����ÿ�ݷ�1��
                //ֻ��һ�ַַ����ڶ���������һ��Ϊ0����ʱ�൱��a[i][j-1]
            else if (i==j)
                a[i][j]=a[i][j-1]+1;
                //��m>nʱ��Ҳ�����������һ����������һ��Ϊ0��
                //�൱��a[i][j-1],�ڶ��֣��Ƚ�j�ֳ�����Ȼ��i-j�ٷֳ�j�ݣ���ʱ�൱��a[i-j][j];
            else if (i>j)
                a[i][j]=a[i-j][j]+a[i][j-1];
        }
    }
    cout<<a[n][k]<<endl;
    return 0;
}
*/ 
�� i �ֳ��� j ���� j ����� (���ظ�)
dp[i][j] = dp[i-j][j] + dp[i][j-1];(i >= j)
dp[i][j] = dp[i][i](i < j)

�� i �ֳ��� j ���� j ����� (���ظ�)
dp[i][j] = dp[i-j][j-1] + dp[i][j-1];(i >= j)
dp[i][j] = dp[i][i](i < j)

�� i �ֳ��� 1 ���� 1 ����������ظ��� 
�Ƚ� i �м�ȥ j ������ �� ��ƽ�� j �У� ��Ϊû��1����� 
��һ��Ϊ 1 �� �����ļ����� 
dp[i][j] = dp[i-j][j] + dp[i-1][j-1](i >= j)
dp[i][j] = dp[i][i](i < j) 

�� i �ֳ��� 1 ���� 1 ����������ظ��� 
dp[i][j] = dp[i-j][j-1] + dp[i-1][j-1](i >= j)
dp[i][j] = dp[i][i](i < j) 
 
��i�ֳ����ɸ�����֮�� 
jΪ����ʱ�� 
dp[i][j] =  dp[i-j][j] + dp[i][j-1](i <= j)
dp[i][j] = dp[i][i](i < j) 
jΪż��ʱ��
dp[i][j] = dp[i][j-1]; 


