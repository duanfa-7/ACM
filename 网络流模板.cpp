#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=205;
const int inf=2147480000;
int n,m,to[N*2],nxt[N*2],w[N*2],head[N],cnt=1,d[N],q[N*4],ans;//d����1�ŵ�ľ��룬��¼·���� 
void add(int x,int y,int v)
{
  to[++cnt]=y;nxt[cnt]=head[x];
  w[cnt]=v;head[x]=cnt;
}//0^1=1,1^1=0,2^1=3,3^1=2,�ʱ�Ŵ�2��ʼ�ȽϷ��㷴��� 
//��2��ʼ������ߣ�head���ö���������������ı�ʱ���ڶ�������д��i�Ϳ��ԡ����� 
bool bfs()//�ж��Ƿ���·������һ�� 
{
   memset(d,0,sizeof(d));
   int h=1,t=1;
   q[1]=1;
   d[1]=1;
   while(h<=t)
    {
     int x=q[h];
	 for(int i=head[x];i;i=nxt[i])
	 if(w[i]&&!d[to[i]])//����������û���߹� 
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
   if(x==n||v==0)return v;//�����յ��˻���û������ 
   int f,ret=0;//ret:�����������ҵ�������������f����������һ��·���Ŀ���ͨ�������� 
   for(int i=head[x];i;i=nxt[i])
   if(d[to[i]]==d[x]+1)//���ҵ����Ǹ�·���� 
   {
	 f=dfs(to[i],min(w[i],v));//��ͨ�����͵����ѹ�����֮��������������Լ������������Сֵ�� 
	 w[i]-=f;//�����ʣ��������ȥf 
	 w[i^1]+=f;//�����ʣ����������f��ʵ�����Ǹ���һ�����ڵĻ��ᣬ�Ե���ʽ�� 
	 v-=f;//����������������ȥf 
     ret+=f;//����������f 
     if(v==0)break;//û���ˣ��˳� 
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
	  add(x,y,v);//ʵ���������v���������Ǹ��������ڻ�������������������  
	  add(y,x,0);	//edges in reverse
	     }
   while(bfs())ans+=dfs(1,inf);//ֻҪ��·���ߡ����������������ޣ����������� 
   cout<<ans<<endl;
return 0;
}

