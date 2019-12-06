#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
inline int read(){
    int X=0,w=0; char ch=0;
    while(ch<'0' || ch>'9') {w|=ch=='-';ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
int tree[800001],pos[200001],val[200001],ans[200001];
void build(int a,int l,int r){
    if(l==r){
    tree[a]=1;
    return;
    }
    int mid=(l+r)>>1;
    build(a*2,l,mid);
    build(a*2+1,mid+1,r);
    tree[a]=tree[a*2]+tree[a*2+1];
    return;
}
void gai(int a,int l,int r,int p,int v){
    tree[a]--;
    if(l==r){
    ans[l]=v;
    return;
    }
    int mid=(l+r)>>1;
    if(tree[a*2]>p)gai(a*2,l,mid,p,v);
    else gai(a*2+1,mid+1,r,p-tree[a*2],v);
    return;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
    build(1,0,n);
    for(int i=1;i<=n;i++){
        pos[i]=read();
        val[i]=read();
    }
    for(int i=n;i>=1;i--){
        gai(1,0,n,pos[i],val[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    }
    return 0;
}
