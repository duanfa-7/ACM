#include<stdio.h>
#include<string.h>
const int maxn=111111;
int main()
{
	int n,e,g,fa,fb;
	long long a[maxn],b[maxn],c[maxn],d[maxn];
	int flag=0,u;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&e,&g);
		c[i]=a[i]+e,d[i]=b[i]+g;
	}
	scanf("%d%d",&fa,&fb);
	for(int i=n;i>=1;i--)
	{
		if(fa>=a[i]&&fa<=c[i]&&fb>=b[i]&&fb<=d[i])
		{
			u=i;
			flag=1;
			break;
		}
	}
	if(flag)
	{
		printf("%d\n",u);
	}
	else 
	{
		printf("-1\n");
	}
	return 0;
	
} 
