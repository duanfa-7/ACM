#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+8;
int fat[maxn];
long long int tot = 0;
struct node{
    int x,y,z;//�ṹ�屣�����x���յ�y���Լ���Ȩz
}f[maxn];
int find(int x)//·��ѹ��
{
    if(fat[x] != x)
        fat[x] = find(fat[x]);
    return fat[x];
}
void unionn(int x,int y)//�ϲ�
{
    int x1=find(x),y1=find(y);
    fat[y1]=x1;
}
bool cmp(node a,node b)
{
    return a.z<b.z;//���ŵĹ���
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
 
    sort(f+1,f+s+1,cmp);//����
 
    for(int i=1;i<=s;i++)
    {
        if(find(f[i].x)!=find(f[i].y))//����ͬһ������
        {
 
            unionn(f[i].x,f[i].y);
 
            tot+=f[i].z;//����Ȩֵ��
 
            k++;
        }
    }
    //printf("k = %d\n" , k);
    if(k<n-1) printf("Concubines can't do it.");
 
    else printf("%lld",tot);
}
