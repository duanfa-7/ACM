#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
int c[maxn] , n;
int lowbit(int t)
{
	return t&(-t);
}
void insert(int k , int d , int max)
{
	while(k <= max)
	{
		c[k] += d;
		k += lowbit(k);
	}
}
long long getsum(int k)
{
	long long sum = 0;
	while(k > 0)
	{
		sum += c[k];
		k -= lowbit(k);
	}
	return sum;
}
int main()
{
	int T , N , a , b;
	char str[100];
	cin >> T >> N;
	while(T--)
	{
		int r;
		for(int i = 1 ; i <= N ; i++)
		{
			cin >> r;
			insert(i , r , N);
		}
		while(cin >> str)
		{
					if(str[0] == 'A')
			{
				cin >> a >> b;
				insert(a , b , N);
			}
			else if(str[0] == 'S')
			{
				cin >> a >> b;
				insert(a , -b , N);
			}
			else if(str[0] == 'Q')
			{
				cin >> a >> b;
				
				int t1 = getsum(a-1);
				int t2 = getsum(b);
				cout << t2 - t1 << endl;
			}
			else if(str[0] == 'E')
			{
				break;
			}
		 } 
	
	}
	return 0;
}
/*
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End

*/ 
