#include <stdio.h>
int main()
{
int a[105][105];
int n , m , t = 1;
int sum = 0;
scanf("%d" , &n);
m = n / 2;
for(int i = 0 ; i < n ; i++)
{
	for(int j = 0 ; j < n ; j++)
	{
		a[i][j] = t++;
	}
}
for(int i = 0 ; i < n ; i++)//ע�������ϵ �����ھ����л���һ������
//�ҹ�ϵ 
{
	for(int j = 0 ; j < n ; j++)
	{
		if(i <= m && j >= m - i && j <= m + i)
		{
			sum +=a[i][j];
		}
		else if(j >= i - m && j <= n - ( i - m + 1) && i > m)
		{
			sum += a[i][j];
		}
	}
	
}
printf("%d" , sum);
	return 0;
}
