#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int l ;
	int r;
}s[100005];
int main()
{
	int t , a , b , n;
	int flag = 0;
	scanf("%d" , &n);
for(int i = 0 ; i < n ; i++)
{
	scanf("%d %d" , &s[i].l , &s[i].r);
}
int PP = max(s[0].l,s[0].r);
for(int i = 0 ; i < n ; i++)
{
	int MIN = min(s[i].l,s[i].r);
	int MAX = max(s[i].l,s[i].r);
	if(PP >= MAX)
		{
			PP = MAX;
		}
		else if(PP >= MIN)
		{
			PP = MIN;
		}
		else if(PP < MIN)
		{
			flag = 1;
			break;
			
		}
}
if(flag == 1)
{
	printf("NO\n");
	
}
else
{
	printf("YES\n");
}
	return 0;
}

