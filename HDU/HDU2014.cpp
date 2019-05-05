#include <stdio.h>
#include <iostream>
#include <algorithm> 
using namespace std;
int main ()
{
	int n  , a[100];
	while(~scanf("%d" , &n))
	{
		int sum = 0;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d" , &a[i]);
		}
		sort(a , a + n);
		for(int i = 1 ; i < n - 1 ; i++)
		{
			sum += a[i] ;
		//	printf("%d \n" , a[i]);
			
		}
			printf("%.2f\n" , sum * 1.0 / (n - 2) );//float wq  = (float)sum;
	}                                               //printf("%.2f\n" , wq / (n - 2));  
	return 0;
 } 
 /*
 类型转换： 
 int a;
有两种办法,
自己手动强转:  float b = (float)a
自动强转,基本上所有语言都是会在混合运算时自动强转为统一数据类型,统一为最高精度的,所以  a*1.0 或  a/1.0就可以了:
float b = a*1.0
*/
