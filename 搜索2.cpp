#include <string.h>
#include <stdio.h>
#include <algorithm> 
#include <queue>
#include <iostream>
#define ull unsigned

using namespace std;
int n;
queue<ull> Q;
ull bfs()
{
	Q.push(1);
	while(!Q.empty())
	{
		ull ans = Q.front();
		Q.pop();
		if(ans % n == 0)
		{
			cout << ans<<endl;
			break;
		}
		else
		{
			Q.push(ans*10);
			Q.push(ans*10+1); 
		}
	}
	return -1;
}

int main()
{
	while(~scanf("%d" , &n) && n)
	{
		bfs();
		
	}
	return 0;
}
