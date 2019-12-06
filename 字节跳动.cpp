#include <bits/stdc++.h>
using namespace std;
int ret = 0 , a = 0 , op = 0;
long long int f[150008] , t = 1;
void init()
{
	for(int i = 1; ; i++)
	{
			int b = i;
			while(1)
			{
				while(b)
				{	
					a = a + (b%10)*(b%10);
					b /= 10;
				}
				if(a == 1)
				{
					f[t] = i;
					t++;
					a = 0;
					break;
				}
				b = a;
				a = 0;
				ret++;
				if(ret >= 10)
				{
					ret = 0;
					 break;
				 }
			}
			if(t == 150001)break;
	}


}
int main()
{
	int t , x;
	init();
	scanf("%d" , &t);
	while(t--)
	{
		scanf("%d" , &x);
		printf("%lld\n" , f[x]);
	}
	return 0;
}

