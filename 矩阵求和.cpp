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
for(int i = 0 ; i < n ; i++)//注意各个关系 类似在矩阵中画出一个菱形
//找关系 
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
