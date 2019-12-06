#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000;
int sg[maxn] , Hush[maxn];
void getsg(int n , int p , int q)
{
	memset(sg , 0 , sizeof(sg));
	for(int i = p+1 ; i <= n ;i++)
	{
		memset(Hush , 0 , sizeof(Hush));
		for(int j = p ; j <= q ; j++)
		{
			Hush[sg[i - j]] = 1;
		}
		for(int j = 0 ; ; j++)
		{
			if(Hush[j] == 0)
			{
				sg[i] = j;
				break;
			}
		}
	}
	for(int i = 0 ; i <= q ; i++)
	{
		cout <<i << ":" << sg[i] << endl;
	}
	
}
int main()
{
	int n , p , q ;
	while(cin >> n >> p >> q)
	{
	//	getsg(n , p , q);
	n--;
		 n %= (p + q);
		 
		if( n < p)
		{
			printf("LOST\n");
		}
		else
		{
			printf("WIN\n");
		}
	}
	return 0;
}
