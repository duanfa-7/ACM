#include <stdio.h>
int main ()
{
	int x , y;
	while(~scanf("%d %d" , &x , &y))
	{
		if(x == 0 && y == 0)//x , y ȡֵ��Χ�и��� �� ������ 
		{
			break;
		}
		int flag = 0;
		for(int i = x ; i <= y ; i++)
		{
			int s = i * i + i + 41;
			for(int j = 2 ; j < s ; j++)
			{
				if(s % j == 0)
				{
					flag++;  //��Ŀ����˵�ж��Ƿ�Ϊ���� ������ĳ�flag= 1�Ļ��� ���ʾ�з��ؼ��� 
					break;
				}
			}
		} 
		 	if(flag)
			{
				printf("Sorry\n");
				
			}
			else
			{
				printf("OK\n");
			}
	}
	return 0;
 } 
