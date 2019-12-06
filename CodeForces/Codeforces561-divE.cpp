#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+8;
vector<int>V[maxn];
bool vis[maxn];
int main()
{
    int m , n , flag;
    int s , x ;
    scanf("%d %d" , &m , &n);
    for(int i = 0 ; i < m ; i++)
    {
        scanf("%d" , &s);
        while(s--)
        {
            scanf("%d" , &x);
            V[i].push_back(x);
        }
    }
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = i+1 ; j < m ; j++)
        {
        	flag = 0;
        	memset(vis , false , sizeof(vis));
           for(int k : V[i])
           {
           		vis[k] = true;
		   }
		   for(int k : V[j])
		   {
			   	if(vis[k])
			   	{
			   		flag = 1;
			   		break;
				}
		   }
		    if(flag==0) break;
        }
        if(flag==0) break;
    }
if(flag)printf("possible\n");
else printf("impossible\n");
    return 0;
}