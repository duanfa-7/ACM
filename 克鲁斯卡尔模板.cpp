#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+8;
int fat[maxn];
long long int tot = 0;
struct node{
    int x,y,z;//结构体保存起点x，终点y，以及边权z
}f[maxn];
int find(int x)//路径压缩
{
    if(fat[x] != x)
        fat[x] = find(fat[x]);
    return fat[x];
}
void unionn(int x,int y)//合并
{
    int x1=find(x),y1=find(y);
    fat[y1]=x1;
}
bool cmp(node a,node b)
{
    return a.z<b.z;//快排的规则
}
int main()
{
    int m,n , s ;
    int k=0;
    scanf("%d%d%d",&n,&m,&s);
     for(int i=1;i<=n;i++) fat[i]=i;
    for(int i = 1 ; i<= m ;i++)
    {
    	scanf("%d%d%d",&f[i].x,&f[i].y,&f[i].z);
    	
    	if(find(f[i].x)!=find(f[i].y))
    	{
			unionn(f[i].x,f[i].y);
    		k++;
		}
	}
    for(int i=1;i<=s;i++)
        scanf("%d%d%d",&f[i].x,&f[i].y,&f[i].z);
 
    sort(f+1,f+s+1,cmp);//快排
 
    for(int i=1;i<=s;i++)
    {
        if(find(f[i].x)!=find(f[i].y))//不在同一集合内
        {
 
            unionn(f[i].x,f[i].y);
 
            tot+=f[i].z;//计算权值和
 
            k++;
        }
    }
    //printf("k = %d\n" , k);
    if(k<n-1) printf("Concubines can't do it.");
 
    else printf("%lld",tot);
}
