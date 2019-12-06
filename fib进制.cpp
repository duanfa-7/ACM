#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	long long int t,x,book[100],ans,cnt;
	long long int fib[100],sum[100];
	fib[0] = 1;
	fib[1] = 2;
	sum[0] = 1;
	sum[1] = 3;
	for(int i = 2; ; i++)
	{
		fib[i] = fib[i-1]+fib[i-2];
		sum[i] = sum[i-1]+fib[i];
		if(sum[i] >1e9)
		{
			break;
		}
	}
	scanf("%lld" , &t);
	while(t--)
	{
		memset(book,0,sizeof(book));
		scanf("%lld" , &x);
		for(int i = 0 ; i < 66 ; i++)
		{
				book[i] = 1;
			if(x <= sum[i])
			{
				ans = sum[i];
				cnt = i;
				break;
			}
		}
		long long int answer = 0;
	//	cout <<"ans ="<<ans<<endl;
	//	cout <<"cnt = "<<cnt<<endl;
		if(x == ans)
		{
			for(int i = cnt ; i>= 0 ; i--)
			{
				answer += (long long)book[i]*pow(2,i);
			}
		}
		else
		{
			for(int i = cnt ; i >= 0 ; i--)
			{
				if( (ans - fib[i]) < x)
				{
				//	cout << "1 :  sum[i] - fib[i] ="<<sum[i] - fib[i]<<endl;
					continue;
				}
				else if( (ans-fib[i]) > x )
				{
				//	cout << "2  :  sum[i] - fib[i] ="<<sum[i] - fib[i]<<endl;
					ans -= fib[i];
					book[i]=0 ;
			//	cout << "book[i] = "<<book[i]<<endl;
					continue;
				}
			else if((ans-fib[i])==x  )
				{
					//cout << "3  :  sum[i] - fib[i] ="<<sum[i] - fib[i]<<endl;
					ans -= fib[i];
					book[i]=0;
				//	cout <<"book[i] = "<<book[i]<<endl; 
					break;
				}
			}
			for(int i = cnt ; i>= 0 ; i--)
			{
			//	cout <<"book[i] = "<<book[i]<<endl;
				answer += (long long)book[i]*pow(2,i);
			}
		}
			printf("%lld\n" , answer);
	 } 

	return 0;
}
