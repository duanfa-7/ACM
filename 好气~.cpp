#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[2005][2005];
char s1[2005] , s2[2005] , x[30];
int  score[30];	
int max(int w , int q)
{
	if(w <= q)
	{
		return q;
	}
	else
	{
		return w;
	}
}
int main()
{
	int N ;
	while(~scanf("%d" , &N))
	{
		scanf("%s" , x);
		for(int i = 0 ; i < N ; i++)
	{
		scanf("%d" , &score[x[i] - 'a']);
	
	}
	scanf("%s%s" , s1 , s2);
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	 memset(dp,0,sizeof(int)*(n1+1));
	 for(int i=0;i<=n2;i++)
            dp[0][i]=0;
	for(int i = 1 ; i <= n1 ; i++)
	{
		for(int j = 1 ; j <= n2 ; j++)
		{
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + score[x[i-1] - 'a'];
			else
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}
	printf("%d\n" , dp[n1][n2]);
	}
//	return 0;
}
