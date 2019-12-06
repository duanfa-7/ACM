#include<stdio.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
int main ()
{
	int N,i,j,M,k,t=0,q=0,f,g,o,u,z,x,s,e,l;
	int *a,*b;
 a=(int *)malloc(1000010*sizeof(int));
 b=(int *)malloc(1000010*sizeof(int));
	scanf("%d",&N);
	a[1]=1;	
	a[0]=1;
	for(j=2;j<=sqrt(1000010);j++)
		{
			if(a[j]==0)
			{
				for(k=2;j*k<=1000010;k++)
				{
					a[j*k]=1;
				}
			}
		
		}
		for(j=2;j<sqrt(1000010);j++)
		{
			if(a[j]==0)
			{
			//	printf("%d ",j);
				b[q]=j;
				q++;
				t++;
			}
		}
	
		
for(i=0;i<N;i++)
	{
	//memset(a,0,sizeof(a));
		scanf("%d",&M);
	//	for(q=0;q<sqrt(1000010);q++)
	//	{
	//		e=b[q];
		//	printf("%d   ",b[q]);
	//	if(b[q]==0)
		//	break;
			//	printf("\n");
		for(int q=0;q<t;q++)
		{
		//	if(b[q]==1)
		//	{
		//		printf("1");
		//	 } 
		if(b[q]<M)
		{
		//	printf("%d  ",b[q]);
		 o=M-b[q];
		 z=b[q];
		 l=b[q+1];
		}
		
	//	printf("\n");
		if(b[q]>M)
		{
		//	printf("\n%d  ",b[q]);
			u=b[q]-M;
			x=b[q];
			s=b[q-1];
		//	printf("%d",x);
			break;
		}
	//	printf("\n");
		//	printf("%d ",b[q]);
			
	//	}
	

		}
	//	printf("\n");
	//	printf("\n%d   ",o);
	//	printf("%d",u);
			//	printf("%d\n",M);
		//	printf("%d %d\n",s,l);
			if(s==M||l==M)
			{
				printf("0\n");
			}
	else if(o>u)
	{
		printf("%d %d\n",x,u);
	}
	else
	printf("%d %d\n",z,o);
	}
	
	return 0;
}
//每行输出两个整数 A B.
//其中A表示离相应测试数据最近的素数，B表示其间的距离。
