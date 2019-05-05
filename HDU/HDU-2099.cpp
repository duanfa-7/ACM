#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int a , b , aa[108];
	while(~scanf("%d %d" , &a , &b) && (a+b))
	{
		int k = 0 ;
		int t = (a*100)% b;
		for(int i = 0 ; i < 100 ; i++)
		{
			if((t + i % b)%b == 0)
			{
				aa[k++] = i;
			}
		}
		for(int i = 0 ; i < k ; i++)
		{
			if(i == k-1)
			{
				printf("%02d\n" , aa[i]);
			}
			else
			{
				printf("%02d " , aa[i]);
			}
		}
	}
	
	return 0;
}
 
