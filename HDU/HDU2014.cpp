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
 ����ת���� 
 int a;
�����ְ취,
�Լ��ֶ�ǿת:  float b = (float)a
�Զ�ǿת,�������������Զ��ǻ��ڻ������ʱ�Զ�ǿתΪͳһ��������,ͳһΪ��߾��ȵ�,����  a*1.0 ��  a/1.0�Ϳ�����:
float b = a*1.0
*/
