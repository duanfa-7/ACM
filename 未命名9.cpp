#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;
int main()
{
	int n,t,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int x1,y1,x2,y2 , flag = 0;
		scanf("%d%d",&x1,&y1);
		if(n == 1 && m == 1)
		{
			puts("No");
			continue;
		}
		if(n > 1 && m == 1)
		{
			printf("Yes %d\n",n+n-2);
			continue;
		}
		int p;
		for(int i = 0 ; i < m - 1 ; i++)
		{
			scanf("%d%d",&x2,&y2);
			if(i == 0) p = y2-y1/x2-x1;
			else 
			{
				t = y2-y1/x2-x1;
				if(t != p)
				{
					flag = 1;
				}
			}
			x1 = x2;y1 = y2;
		}
		if(m == 2 && abs(p) == 1) {puts("No");continue;}
		if(!flag) printf("Yes %d\n",n+n-2);
		else puts("No");
	}
	
}

