#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <math.h> 
double dp[25][25];
struct node 
{
	double lv;
	double num;
	int num1;
}a[100];
int main ()
{
	int n;
	double ans;

	while(~scanf("%d %lf %lf %lf %lf" , &n , &a[1].lv , &a[2].lv , &a[3].lv , &a[4].lv))
	{
			for(int i = 0  ; i < 25 ; i++)
	{
		for(int j = 0 ; j <= 25 ; j++)
		{
			dp[i][j] = 1;
		}
	}
		a[1].num1 =  1;a[2].num1 = 2;a[3].num1 = 3; a[4].num1 = 5;
	a[1].num = pow(1 + a[1].lv , 1); a[2].num = pow(1 + a[2].lv , 2) ;a[3].num = pow(1 + a[3].lv , 3);a[4].num = pow(1 + a[4].lv , 5);
	printf("%.5f %.5f %.5f %.5f \n" , a[1].num , a[2].num , a[3].num , a[4].num);
	for(int i = 1 ; i <= 4; i++)
	{
		
		for(int j = 1 ; j <= n ; j++)
		{
			
			dp[i][j] = max(dp[i][j], dp[i-1][j- a[i].num1] * a[i].num);
			
		}
	}
	for(int i = 1 ; i <= 4 ; i++)
	{
		for(int j = 0 ; j <= n ; j++)
		{
			printf("%.5lf" , dp[i][j]);
		}
		printf("\n");
	}
//	printf("%.5lf\n" , dp[4][n]);
	}
	
	return 0;
}
