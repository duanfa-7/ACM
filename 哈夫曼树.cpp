
#include<iostream> 
#include<iomanip> 
#include<string.h> 
#include <windows.h> 
using namespace std;
typedef struct { 
	int weight; 
	int parent,lchild,rchild; 
	char data;  
}HTNode,*HuffmanTree; 
typedef char **HuffmanCode;  
void tongji(char *a,int *w,char *d,int &n) 
{ 
	int j,i,k; 
	j=0;
	for(i=0;i<100&&a[i]!='\0';i++)
	{ 
		for(k=0;k<j;k++){
			if(a[i]==d[k]) 
			{ 
				w[k]++; 
				break; 
			} 
		} 
		if(k==j)
		{ 
			d[j]=a[i]; 
			w[j]++; 
			j++;
		} 
	} 
	n=j; 
	d[j]='\0'; 
}  
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char *d)//构造赫夫曼树
{ 
	if(n<=1)return; 
	int m=2*n-1; 
	HT=new HTNode[m+1]; 
	HuffmanTree p; 
	int i; 
	for(p=HT+1,i=1;i<=n;i++,++p) 
	{ 
		p->data=d[i-1]; 
		p->lchild=p->parent=p->rchild=0; 
		p->weight=w[i-1]; 
	}	 
	for(;i<=m;++i,++p) 
	{ 
		p->lchild=p->parent=p->rchild=0; 
		p->weight=0; 
	} 
	for(i=n+1;i<=m;++i)
	{ 
		int s1,s2,u,t; 
		for (u=1;u<=i-1;u++)
			if(HT[u].parent==0)
			{s1=u;break;} 
		for(u=u+1;u<=i-1;u++)
		{ 
			if(HT[s1].weight>HT[u].weight&&HT[u].parent==0) 
			s1=u; 
		} 
		for(t=1;t<=i-1;t++) 
		if(HT[t].parent==0&&t!=s1){s2=t;break;} 
		for(t=t+1;t<=i-1;t++) 
		{ 
			if(HT[s2].weight>HT[t].weight&&HT[t].parent==0&&t!=s1) 
			s2=t; 
		} 
		HT[s1].parent=i;HT[s2].parent=i; 
		HT[i].lchild=s1;HT[i].rchild=s2; 
		HT[i].weight=HT[s1].weight+HT[s2].weight; 
	} 
	HC=new char*[n+1]; 
	char *cd=new char[n]; 
	cd[n-1]='\0'; 
	int start,c,f;
	for(i=1;i<=n;++i)
	{ 
		start=n-1; 
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent) 
		if(HT[f].lchild==c) 
			cd[--start]='0'; 
		else 
			cd[--start]='1'; 
			HC[i]=new char[n-start]; 
			strcpy(HC[i],&cd[start]); 
	} 
	delete(cd);
}  
void bianma(HuffmanCode HC,char *a,char *d,char *bc) 
{	
	int m1=0,m2=0;
	int i=0,j;
	while(a[i]!='\0')
	{
		j=0;
		while(d[j]!='\0') 
		{ 
			if (a[i]==d[j]) 
			{ 
				m1=0; 
				while(HC[j+1][m1]!='\0') 
				bc[m2++]=HC[j+1][m1++]; 
				break; 
			} 
			j++;
		} 
		i++;
	} 
	bc[m2]='\0';
} 
void yima(HuffmanTree HT,int n,char*bc) 
{ 
	int m=2*n-1; 
	for (int i=0;bc[i]!='\0';++i) 
	{ 
		if (HT[m].lchild==0) 
		{		 
			cout<<HT[m].data; 
			m=2*n-1; 
		} 
		if(bc[i]=='0') 
			m=HT[m].lchild; 
		else 
			m=HT[m].rchild; 
	} 
	cout<<HT[m].data<<endl; 
} 
int main() 
{  
	char a[100]; 
	char d[100];char bc[1000]; 
	int w[100],n=0; 
	HuffmanTree HT; 
	HuffmanCode HC;  
	cout<<"请输入字符：\n"; 
	cin>>a; 
	for(int ak=0;ak<100;ak++)
	w[ak]=0; 
	tongji(a,w,d,n); 
	HuffmanCoding(HT,HC,w,n,d); 
	cout<<"霍夫曼编码为："<<endl; 
	cout<<"原码"<<"权值"<<"二进制码"<<endl;  
	for(int s=0;s<n;s++)
	cout<<d[s]<<" "<<w[s]<<" "<<HC[s+1]<<endl; 
	bianma(HC,a,d,bc); 
	cout<<"密文为："; 
	cout<<bc<<endl;  
	cout<<"开始译码："<<endl; 
	yima(HT,n,bc);  
	return 0; 
}
