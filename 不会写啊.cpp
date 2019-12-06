#include <stdio.h>
#include <iostream>
using namespace std;
#define N -9999;
int dp[100][100];
void init()
{
	for(int i = 0 ; i < 100 ; i++)
	{
		for(int j = 0 ; j < 100 ; j++)
		{
			dp[i][1] = 1;
			dp[1][j] = 1;
		}
	}
}
int main()
{
	int t , m , ans;
	cin >> t;
	while(t--)
	{
		init();
		int ans ;
		cin >> m;
			for(int i = 1 ; i <= 2 ; i++)
			{
				for(int j = 1 ; j  <= m ; j++)
				{
					if(i < j)
					{
						dp[i][j] = dp[i][i];
					}
					else if(i == j)
					{
						dp[i][j] = dp[i][j-1] + 1;
					}
					else
					{
						dp[i][j] = dp[i-j][j] + dp[i][j-1];
					}
				}
			}
//			for(int i =  1 ; i <= 2 ; i++)
//			{
//				for(int j = 1 ; j <= m ; j--)
//				{
//					cout << /*"dp[i][j] = "<<*/dp[i][j] << " ";
//				}
//				cout << endl;
//			}
	//cout << "ans = " << ans << endl;
		cout << dp[2][m] << endl;
	}
	
	return 0;
}
