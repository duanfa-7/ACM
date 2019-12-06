#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x ;
	int y;
	int z;
};
int cmp(node a , node b)
{
	if(a.x == b.x)
	{
		return a.y < b.y;
	}
	else
	{
		return a.x < b.x;
	}
}
int main()
{
	int n , m ;
	node r[100008];
	
	int book[100008]={0};
	node a[100008] , b[100008];
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].z = i;
		book[a[i].x]++;
	}
	sort(a , a+m , cmp);
	int num = 1;
	for(int i = 0 ; i < m ; i++)
	{
		r[a[i].z].x = a[i].x;
		r[a[i].z].y = num;
		num++;
		if(a[i].x != a[i+1].x)
		num = 1;
	}
	for(int i = 0 ; i < m ; i++)
	{
		printf("%06d" , r[i].x);
		printf("%06d\n" , r[i].y);
	}
	return 0;
}
