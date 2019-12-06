#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int c[maxn] , ma[maxn];
//���������ƣ�ȡ����һ 
int lowbit(int t)//��ĳһ�����Ķ����Ʊ�ʾ����͵�һλ1���ٸ����ӣ�x = 6��
{ 				//���Ķ�����Ϊ110����ôlowbit(x)�ͷ���2����Ϊ���һλ1��ʾ2��
	return t&(-t);
 } 
 //�޸� 
void insert(int k , int d , int n)//���ϸ���
{
	while(k <= n)
	{
		c[k] += d;
		k += lowbit(k);
	}
 } 
 //��� 
 int getsum(int k) //sum[7]=A[1]+A[2]+A[3]+A[4]+A[5]+A[6]+A[7] ;  
 {					//sum[7]=C[4]+C[6]+C[7]; 
 	int sum = 0;
 	while(k > 0)
 	{
 		sum += c[k];
 		k -= lowbit(k);
	 }
	 return sum;
 }
int main()
{
	int n , k;
	while(scanf("%d %d" , &n , &k) != EOF)
	{
		memset(c , 0 , sizeof(c));
		for(int i = 1 ; i <= n ; i++)
		{
			insert(i , 1 , n);
			ma[i] = 1;
		}
		while(k--)
		{
			int f , a , b;
			scanf("%d %d %d" , &f , &a , &b);
			if(f == 0)//�ñ仵 �� ����� 
			{
				if(a > b){int tmp = a ; a = b ; b = tmp;}
				if(a == 1 && b == n)
				{
					if(ma[b] == 1)
					{
						insert(b , -1 , n);
						ma[b] = 0;
					}
					else
					{
						insert(b , 1 , n);
						ma[b] = 1;
					}
				}
				else
				{
					if(ma[a] == 1)
					{
						insert(a , -1 , n);
						ma[a] = 0;
					}
					else
					{
						insert(a , 1 , n);
						ma[a] = 1;
					}
				}
			}
			if(f == 1)
			{
				if(a > b){int tmp = a ; a = b ; b = tmp;}
				int t1 , t2 , t3;
				t1 = getsum(a-1);
				t2 = getsum(b-1);
				int flag = 0;
				if(t2 - t1 == b - a)
				{
					printf("YES!\n");
					flag = 1;
				}
				if(!flag)
				{
					t3 = getsum(n)-t2;
					if(t3+t1 == n-b+a)
					{
						printf("YES!\n");
						flag = 1;
					}	
				}
				if(flag == 0)
				{
					printf("NO\n");
				}
			 } 
		}
	}
	return 0 ;
}
/*
5 10
1 2 5
0 4 5 
1 4 5
0 2 3
1 3 4
1 1 3
0 1 2
0 2 3
1 2 4
1 2 5 
*/ 
