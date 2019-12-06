#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
using namespace std;
#define maxn 1000050
char b[maxn];
long long a,c;
long PHI;
//�� b < c ֱ���ÿ����� �� �� b �ر�� �� ����ȡģ 
int phi(int x)//ŷ������
{
	int i,j;
	int num = x;
	for(i = 2; i*i <= x; i++)
	{
		if(x % i == 0)
		{
			num = (num/i)*(i-1);
			while(x % i == 0)
			{
				x = x / i;
			}
		}
	}
	if(x != 1) num = (num/x)*(x-1);
	return num;
}
long long power(long long a,long long b,long long c)//������
{
	long long base=a,sum=1;
	while(b!=0)
	{
		if(b&1)
		sum=(sum*base)%c;
		base=(base*base)%c;
		b>>=1;
	}
	return sum%c;
}
int main()
{
	while(~scanf("%lld%s%lld",&a,b,&c))
	{
		PHI=phi(c);//c��ŷ������
		int len=strlen(b);
		long long num=0;
		for(int i=0;i<len;i++)//����ȡģ ͬ��ģ����
		{
			num=(num*10+(int)(b[i]-'0'));
			if(num>c)break;
		}
		if(num<=c)
		{
			printf("%lld\n",power(a,num,c));
		}
		else
		{
			num=0;
			for(int i=0;i<len;i++)//����ȡģ ͬ��ģ����
			{
				num=(num*10+(int)(b[i]-'0'))%PHI;
			}
			num+=PHI;
			printf("%lld\n",power(a,num,c));
		}
	}
	return 0;
}

