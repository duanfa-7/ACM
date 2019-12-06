#include <bits/stdc++.h>
using namespace std;
bool vis[10000];
int book[10000];
int main()
{
	int x , y , num , n , m , t;
	string str;
	scanf("%d" , &t);
	while(t--)
	{
		scanf("%d %d" , &n , &m);
		memset(vis , false , sizeof(vis));
		memset(book , 0 , sizeof(book));
		int ans = 0 , cnt = 0;
		while(m--)
		{
			scanf("%d %2d:%2d" , &num , &x , &y);
			cin >> str;
			if(str[0] == 'A')
			{
				if(!vis[num])
				{
					vis[num] = true;
					cnt++;
					int op = x * 60 + y + book[num]*20;
					ans += op;
				}
			}
			else
			{
				if(!vis[num])
				{
					book[num]++;
				}
			}
		}
		printf("%d %d\n" , cnt , ans); 
	}
	return 0;
}
/*
1
3 5
1002 00:02 WA
1003 00:05 WA
1003 00:06 WA
1003 00:07 AC
1002 04:59 AC
*/