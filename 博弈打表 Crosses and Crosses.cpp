#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 2005;
int sg[maxn];
int vis[maxn];
void init()
{
    memset(sg,0,sizeof(sg));
    sg[0] = 0;
    sg[1] = 1;
    sg[2] = 1;
    sg[3] = 1;
    sg[4] = 2;
    sg[5] = 2;
    for(int i = 6 ; i < maxn ;i++)
    {
    
        memset(vis,0,sizeof(vis));
        for(int j = 3;j <= i;j++)
        {
            vis[sg[j-3]^sg[i-j-2]] = 1;
       }
        for(int j = 0 ;;j++)
        {
            if(vis[j]==0)
            {
                sg[i] = j;
                break;
            }
        }
    
         
    }
//     for(int i = 0 ; i<maxn ; i++)
//     {
//     	 cout<<"i:"<<i<<" sg[i]"<<sg[i]<<endl;
//     	 printf("SG[%d] = %d\n",i,sg[i]);
//	 }
}
int main()
{
	init();
    //函数打印规律
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(sg[n] == 0)
         printf("2\n");
        else
         printf("1\n");
    }
    return 0;
}




