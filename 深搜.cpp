#include <iostream>
#include <cstring>
using namespace std;
int MAP[100][100];
int vis[100][100];
int DIR[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n;
int flag=0;
void dfs(int x,int y)
{
	if(x==n-1&&y==n-1)
	{
		flag=1;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		int X=x+DIR[i][0]; 
		int Y=y+DIR[i][1];
		if(MAP[X][Y]==1&&vis[X][Y]==0&&X>=0&&Y>=0&&X<n&&Y<n)
		{
			vis[X][Y]=1;
			dfs(X,Y);
		}
	}
}
int main ()
{
	memset(MAP,0,sizeof(MAP));
	memset(vis,0,sizeof(vis));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>MAP[i][j];
		}
	}
	if(flag==1)
	{
		cout<<"YES!"<<endl;
	}
	else
	{
		cout<<"NO!"<<endl;
	}
	return 0;
}
