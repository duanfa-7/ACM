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
			dp[i][1] = 1;//将I分成一份 ， 有一种
			dp[1][j] = 1;//将1分成不大于j份 ， 一种
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
		{//i < j 时 ， 相当于将i分成i份
			if(i < j )
			{
				dp[i][j] = dp[i][i];
			}

                        //i==j时 ， 分成两种 ， 一种是只由1组成 ，只有一种，另外一种是分成小于j份，即至少有一份是空； 
			else if( i == j)
			{
				dp[i][j] = dp[i][j-1] + 1;
			}
			else//i>j时 ，分成j份和小于j份的情况 

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
long long a[400][400];//a[n][k]表示将数n，分成k份，每份可以是任意值
int main()
{
    long long n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        a[i][1]=1;//将i分成1份，只有一种分法
    }
    for (int j=1;j<=k;j++)
    {
        a[1][j]=1;//将1分成j，有一种
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
        {
                //当i<j时，因为此时最多分成i份，实际上相当于将i分成i份
            if(i<j)
                a[i][j]=a[i][i];
                //当i==j时，分两种情况，一种是每份分1，
                //只有一种分法，第二种至少有一份为0，此时相当于a[i][j-1]
            else if (i==j)
                a[i][j]=a[i][j-1]+1;
                //当m>n时，也分两种情况，一种是至少有一份为0，
                //相当于a[i][j-1],第二种，先将j分出来，然后将i-j再分成j份，此时相当于a[i-j][j];
            else if (i>j)
                a[i][j]=a[i-j][j]+a[i][j-1];
        }
    }
    cout<<a[n][k]<<endl;
    return 0;
}
*/ 
将 i 分成有 j 和无 j 的情况 (可重复)
dp[i][j] = dp[i-j][j] + dp[i][j-1];(i >= j)
dp[i][j] = dp[i][i](i < j)

将 i 分成有 j 和无 j 的情况 (不重复)
dp[i][j] = dp[i-j][j-1] + dp[i][j-1];(i >= j)
dp[i][j] = dp[i][i](i < j)

将 i 分成有 1 和无 1 的情况（可重复） 
先将 i 中减去 j 的数量 ， 再平分 j 中， 则为没有1的情况 
留一个为 1 ， 其他的继续分 
dp[i][j] = dp[i-j][j] + dp[i-1][j-1](i >= j)
dp[i][j] = dp[i][i](i < j) 

将 i 分成有 1 和无 1 的情况（不重复） 
dp[i][j] = dp[i-j][j-1] + dp[i-1][j-1](i >= j)
dp[i][j] = dp[i][i](i < j) 
 
将i分成若干个奇数之和 
j为奇数时： 
dp[i][j] =  dp[i-j][j] + dp[i][j-1](i <= j)
dp[i][j] = dp[i][i](i < j) 
j为偶数时：
dp[i][j] = dp[i][j-1]; 


