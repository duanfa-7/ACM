#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
struct node
{
	int val;
	int weg;
}a[30005];
struct node1
{
	int num;
	int money;
	int ans;
}b[30005];
bool cmp( node a , node b)
{
	return a.val<b.val;
}
bool cmp1(node1 x , node1 y)
{
	return x.money < y.money;
}
bool cmp2(node1 n , node1 m)
{
return 	n.num < m.num;
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d" , &n , &m);
		for(int i = 0 ; i < n ;  i++)
		{
			scanf("%d %d" , &a[i].val,&a[i].weg);
		}
		sort(a,a+n,cmp);
		for(int i = 1 ; i < n ; i++)
		{
			if(a[i].weg < a[i-1].weg)
			{
				a[i].weg = a[i-1].weg;
			}
		}
		for(int j = 0 ; j < m ; j++)
		{
			b[j].num = j;
			scanf("%d",&b[j].money);
		}
		sort(b,b+m,cmp1);
		int maxn=0 , r = 0;
		 for(int i = 0 ; i < m ; i++)
		 {
			while(b[i].money>=a[r].val)
			{
				maxn = max(maxn,a[r].weg);
				if(r >= n)
				{
					break;
				}
				r++;
			}
			b[i].ans = maxn;
		 }
		 sort(b, b+m,cmp2);
		 for(int i = 0 ; i < m ; i++)
		 {
		 	printf("%d\n" , b[i].ans);
		 }
	}
	return 0;
}
/*

2
3 3
1 100
10 1000
1000000000 1001
9
10
1000000000
3 3
1 100
10 1000
1000000000 1001
9
10
1000000000
*/
