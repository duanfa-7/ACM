#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
}v[1010000]; //x表示值，y表示位置 可以理解为下标
int a[1010000],n,m,mx[1010000],mn[1010000];
void getmin()
{
    int i,head=1,tail=0;// 默认起始位置为1 因为插入是v[++tail]故初始化为0
    for(i=1;i<m;i++)
    {
        while(head<=tail && v[tail].x>=a[i]) tail--;
        v[++tail].x=a[i],v[tail].y=i;
                // 根据题目 前m-1个先直接进入队列
    }
    for(;i<=n;i++)
    {
        while(head<=tail && v[tail].x>=a[i]) tail--;
       
        v[++tail].x=a[i],v[tail].y=i;
        
        while(v[head].y<i-m+1) head++;
        mn[i-m+1]=v[head].x;
        
               // 道理同上，当然了 要把已经超出范围的从head开始排出
               //  然后每个队首则是目前m个数的最小值
    }
}
void getmax() //维护递减队列，超过目标数head++,得到的肯定是最大的 
{			//遇到比前一个小的数tail++ ，往后排队
			//遇到比之前大的数tail-- , 覆盖了当前的值。 
    int i,head=1,tail=0;
    for(i=1;i<m;i++)
    {
        while(head<=tail && v[tail].x<=a[i]) tail--;
        v[++tail].x=a[i],v[tail].y=i;
    }
    for(;i<=n;i++)
    {
        while(head<=tail && v[tail].x<=a[i]) tail--;
        v[++tail].x=a[i],v[tail].y=i;
        while(v[head].y<i-m+1) head++;
        mx[i-m+1]=v[head].x;
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    getmin();
    getmax();
    for(i=1;i<=n-m+1;i++)
    {
        if(i==1)printf("%d",mn[i]);
        else printf(" %d",mn[i]);
    }
    printf("\n");
    for(i=1;i<=n-m+1;i++)
    {
        if(i==1)printf("%d",mx[i]);
        else printf(" %d",mx[i]);
    }
    printf("\n");
    return 0;
}
