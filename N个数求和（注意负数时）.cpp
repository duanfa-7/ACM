#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
long long int lalala(long long int x , long long int y)
{
	return y == 0 ? x : lalala(y , x % y);
}
long long int dududu(long long int m , long long int n)
{
	return (m * n)/lalala(m,n);
}
int main()
{
	long long int p , rr , o , cc;
	long long int n , a[105] , b[105];
	long long int sum = 1 ;
	long long int  wq = 0;
	scanf("%lld" , &n);
	for(long long int i = 0 ; i < n ; i++)
	{
		scanf("%lld/%lld" , &a[i] , &b[i]);
	//	printf("666");
	}
	for(long long int i = 0 ; i < n ; i++)
	{
	sum = dududu(sum , b[i]);
	}
	for(long long int i = 0 ; i < n ; i++)
	{
		wq += a[i] * (sum / b[i] );
	}
//	printf("wq = %d\n" , wq);
//	printf("sum = %d\n" , sum);
	
//	printf("wq == %d , sum == %d\n" , wq , sum);
//	if(wq < 0 && sum < 0)
//	{
//		wq = abs(wq);
//		sum = abs(sum);
//	}
if(abs(wq) >= abs(sum))
{
	
 	 p = wq / sum;
 	 //printf("p == %d", p);
 	 if(wq % sum == 0)
 	 {
 	 	printf("%lld\n" , p);
	  }
	  else
	  {
	  	printf("%lld " , p);
	  	o = wq % sum;
	 //	printf(" o == %d , sum == %d" , o , sum);
		rr = lalala(o , sum);
	//	printf("rr = %d" , rr);
	//	if(o != 0)
	//	{
			printf("%lld/%lld" , o/rr , sum/rr);
	//	}
			
	  }
}
else
{
	if(wq == 0)
	{
		printf("0");
	}
	else
	{
		cc = lalala(wq , sum);
	//printf("rr = %d" , rr);
	printf("%lld/%lld" , wq/cc , sum/cc);
	}

}


	return 0;
 } 
