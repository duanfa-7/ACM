#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
}v[1010000]; //x��ʾֵ��y��ʾλ�� �������Ϊ�±�
int a[1010000],n,m,mx[1010000],mn[1010000];
void getmin()
{
    int i,head=1,tail=0;// Ĭ����ʼλ��Ϊ1 ��Ϊ������v[++tail]�ʳ�ʼ��Ϊ0
    for(i=1;i<m;i++)
    {
        while(head<=tail && v[tail].x>=a[i]) tail--;
        v[++tail].x=a[i],v[tail].y=i;
                // ������Ŀ ǰm-1����ֱ�ӽ������
    }
    for(;i<=n;i++)
    {
        while(head<=tail && v[tail].x>=a[i]) tail--;
       
        v[++tail].x=a[i],v[tail].y=i;
        
        while(v[head].y<i-m+1) head++;
        mn[i-m+1]=v[head].x;
        
               // ����ͬ�ϣ���Ȼ�� Ҫ���Ѿ�������Χ�Ĵ�head��ʼ�ų�
               //  Ȼ��ÿ����������Ŀǰm��������Сֵ
    }
}
void getmax() //ά���ݼ����У�����Ŀ����head++,�õ��Ŀ϶������� 
{			//������ǰһ��С����tail++ �������Ŷ�
			//������֮ǰ�����tail-- , �����˵�ǰ��ֵ�� 
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
