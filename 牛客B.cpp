#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
int t , ans = 0;
int flag = 0 , flag1 = 0 , flag2 =0,flag3 = 0 ;
int book[50];
memset(book , 0 , sizeof(book));
for(int i = 0 ; i < 6 ; i++)
{
	scanf("%d" , &t);
	book[t]++;
}
for(int i =0 ;i < 10;i++)
{
	if(book[i] != 0)
	{
	//	printf("book[%d] = %d\n" , i,book[i]);
		ans++;
		if(book[i] == 6)
		{
			flag2 = 1;
		}
		if(book[i] == 5)
		{
			flag3 = 1;
		 } 
		if(book[i] == 4)
		{
		//	printf("===");
			flag = 1;
		//	ans++;
		}
		if(book[i] == 2)
		{
			flag1 = 1;
		//	printf("----");
		//	ans++;
		}
		if(ans == 6)
		{
			break;
		}
	}
}
//printf("flag = %d  flag1 = %d\n" , flag , flag1);
if(flag == 1 && flag1 == 1||flag2 == 1)
{
	printf("Elephant\n");
}
 else if(flag == 1 && flag1 == 0|| flag3 == 1)
{
	printf("Bear\n");
}
else
{
	printf("Hernia\n");
}
	return 0;
}
