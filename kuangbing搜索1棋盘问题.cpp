#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n , k  , ans;
char ch[10][10];
int vis[100];
int dfs(int x , int k)//分别表示行数和棋子数
{
    if(k == 0)
    {
        ans++;
        return 0;
    }
    if(x > n)
    {
        return 0;
    }
    
        for(int j = 1 ; j <= n ; j++)
        {
            if(ch[x][j] == '#' && vis[j] == 0)
            {
                vis[j] = 1;
                dfs(x+1 , k-1);
                vis[j] = 0;
            }
        }
    dfs(x+1 , k);
    return 0;
}
int main()
{
    while(cin >> n >> k)
    {
    	if(n == -1 && k == -1)
    	{
    		break;
		}
    	ans = 0;
        memset(vis , 0 , sizeof(vis));
        for(int i = 1 ;i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                cin >> ch[i][j];
            }
        }
		dfs(1 , k);
        cout << ans << endl;
    }
    return 0;
}
