#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
struct Matrix
{
	int m[maxn][maxn];
};
Matrix Mul(Matrix a,Matrix b)
{
	Matrix c;
	for(int i = 1 ; i <= maxn ; i++)
	{
		for(int j = 1 ; j <= maxn ; j++)
		{
			c.m[i][j] = 0;
		}
	}
	for(int i = 1 ; i <= maxn ; i++)
	{
		for(int j = 1 ; j <= maxn ; j++)
		{
			for(int k = 1 ; k <= maxn ; k++)
			{
				c.m[i][j] += a.m[i][k]*b.m[k][j];//一般题目会让取余 
			 } 
		}
	}
	return c;
}
Matrix fastm(Matrix a , int n)
{
	Matrix res;
//	memset(res.m , 0 , sizeof(res.m));
	for(int i = 1 ; i <= maxn ; i++)
	{
		for(int j = 1 ; j <= maxn ; j++)
		{
			if(i == j)
			{
				res.m[i][j] = 1;
			}
			else
			{
				res.m[i][j] = 0;
			}
		}
	}
	while(n)
	{
		if(n % 2 == 1)
		{
			res = Mul(res , a);
			n--;
		}
		else
		{
			a = Mul(a,a);
			n = n / 2;
		}
	}
	return res;
} 
int main()
{
	return 0;
 } 
