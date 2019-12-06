#include <bits/stdc++.h>
using namespace std;
int a[100] , book[100] ,b[100] , c[100];
int main()
{
	string str;
	map<string , int>M;
	int p = 0 , q = 0 , w = 0 ,lj , flag;
	for(int i = 0 ; i < 3; i++)
	{
		cin >> str;
		if(str[1] == 's')
		{
			a[p++] = str[0]-'0';
		}
		else if(str[1] == 'm')
		{
			b[q++] = str[0]-'0';
		}
		else
		{
			c[w++] = str[0]-'0';
		}
	}
	sort(a , a+p);
	sort(b , b+q);
	sort(c , c+w);
	int t1 = 1 , t2 = 1 , t = 0;lj = 1;flag  =0;
	for(int i = 0 ; i < p-1 ; i++)
	{
		
		if(a[i+1] == a[i])
		{
			t1++;
		}
		if(a[i+1] == a[i]+1)
		{
			t2++;
		}
		if(flag == 0 &&a[i+1] == a[i]+2)
		{
			flag = 1;
			lj++;
		}
	}
	t2 = max(t2 , lj);
	t = max(t1 , t2);
	int r1 = 1 , r2 = 1 , r = 0;lj = 1;flag = 0;
	for(int i = 0 ; i < q-1 ; i++)
	{
		
		if(b[i+1] == b[i])
		{
			r1++;
		}
		if(b[i+1] == b[i]+1)
		{
			r2++;
		}
		if(flag == 0 &&b[i+1] == b[i]+2)
		{
			flag = 1;
			lj++;
		}
	}
	r2 = max(r2 , lj);
	r = max(r1 , r2);
	int f1 = 1 , f2 = 1 , f = 0;	lj = 1;flag = 0;
	for(int i = 0 ; i < w-1; i++)
	{
		
		if(c[i+1] == c[i])
		{
			f1++;
		}
		if(c[i+1] == c[i]+1)
		{
			f2++;
		}
		if(flag == 0 && c[i+1] == c[i]+2)
		{
			flag = 1;
			lj++;
		}
	}
	f2 = max(f2 , lj);
	f = max(f1 , f2);
	int ans = 0;
	ans = max(f , max(r , t));
	if((p==3&&t==3)||(q==3&&r==3)||(w==3&&f==3))
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n" , 3-ans);
	}
	return 0;
}