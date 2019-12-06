#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=205;
const int inf=2147480000;
int n,m,to[N*2],nxt[N*2],w[N*2],head[N],cnt=1,d[N],q[N*4],ans;//d：到1号点的距离，记录路径。 
void add(int x,int y,int v)
{
  to[++cnt]=y;nxt[cnt]=head[x];
  w[cnt]=v;head[x]=cnt;
}//0^1=1,1^1=0,2^1=3,3^1=2,故编号从2开始比较方便反向边 
//从2开始建反向边，head不用动，搜索连接自身的边时，第二个条件写成i就可以。方便 
bool bfs()//判断是否还有路，宽搜一下 
{
   memset(d,0,sizeof(d));
   int h=1,t=1;
   q[1]=1;
   d[1]=1;
   while(h<=t)
    {
     int x=q[h];
	 for(int i=head[x];i;i=nxt[i])
	 if(w[i]&&!d[to[i]])//还能流并且没被走过 
	   {
	      d[to[i]]=d[x]+1; 
	      q[++t]=to[i];
	   }
	   h++;
    }
   if(d[n])return true;
   return false;
}
int dfs(int x,int v)
{
   if(x==n||v==0)return v;//流到终点了或者没有流了 
   int f,ret=0;//ret:本次搜索能找到的所有流量，f：本次搜索一条路径的可以通过的流量 
   for(int i=head[x];i;i=nxt[i])
   if(d[to[i]]==d[x]+1)//在找到的那个路径上 
   {
	 f=dfs(to[i],min(w[i],v));//能通的流就等于搜过后面之后允许的流，和自己允许的流的最小值。 
	 w[i]-=f;//正向边剩余流量减去f 
	 w[i^1]+=f;//反向边剩余流量加上f。实际上是给他一个反悔的机会，自调整式。 
	 v-=f;//可以流过得数量减去f 
     ret+=f;//总流量加上f 
     if(v==0)break;//没流了，退出 
   } 
  return ret;
}
int main()
{
   cin>>m>>n;
   for(int i=1;i<=m;i++) 
   {
      int x,y,v;
	  cin>>x>>y>>v;
	  add(x,y,v);//实际上这里的v，建立的是该条边现在还可以流过多少流量。  
	  add(y,x,0);	//edges in reverse
	     }
   while(bfs())ans+=dfs(1,inf);//只要有路就走。假设他可以流无限，再慢慢调整 
   cout<<ans<<endl;
return 0;
}

