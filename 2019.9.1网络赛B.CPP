#include<bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
using namespace std;
typedef long long LL;typedef pair<LL,bool> data;
const LL maxn=6666666,maxm=6666666;

LL te,m,n;
LL p[maxm+5],phi[maxm+5];bool pri[maxm+5];
LL av;
#define Eoln(x) ((x)==10||(x)==13||(x)==EOF)
LL Scan()
{
    LL res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
void Out(LL a)
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
void Make()
{
    pri[1]=true;phi[1]=1;
    for (LL i=2;i<=1000005;i++)
    {
        if (!pri[i]) p[++p[0]]=i,phi[i]=i-1;
        for (LL j=1,t;j<=p[0]&&(t=p[j]*i)<=m;j++)
        {
            if (i%p[j]) phi[t]=phi[i]*phi[p[j]],pri[t]=true;
            else
            {phi[t]=phi[i]*p[j];pri[t]=true;break;}
        }
    }
}
LL poww(LL a,LL b,LL c)//������
{
	LL base=a,sum=1;
	while(b!=0)
	{
		if(b&1)
		sum=(sum*base)%c;
		base=(base*base)%c;
		b>>=1;
	}
	return sum%c;
}
LL gcd(LL a,LL b) {if (!b) return a;return gcd(b,a%b);}
/*inline data Pow(LL w,LL b,LL MOD)
{
    LL s=1;bool fl=true;
    while (b)
    {
        if (b&1) {if ((s*=w)>=MOD) fl=false;s%=MOD;}
        b>>=1;if (b) {if ((w*=w)>=MOD) fl=false;w%=MOD;}
    }
    return mp(s,fl);
}
data Solve(LL st,LL sa,LL MOD)
{
    if (MOD==1) return mp(0,false);
    if (st==n) return mp(sa%MOD,sa<MOD);
    data b=Solve(st+1,sa,phi[MOD]);
    if (gcd(sa,MOD)==1) return Pow(sa,b.fr,MOD);
    if (!b.sc) b.fr+=phi[MOD];return Pow(sa,b.fr,MOD);
}*/
LL oule(LL a,LL b,LL mod)
{
    if(mod==1) return 0;
    if(b==1) return a%mod;
    if(gcd(a,mod)==1) return poww(a,oule(a,b-1,phi[mod]),mod);
    return poww(a,oule(a,b-1,phi[mod])+phi[mod],mod);
}
int main()
{
    //scanf("%d",&te);
    ios::sync_with_stdio(false);
    cin>>te;
    Make();
    while(te--)
    {
       cin >> av >> n >> m;
       printf("%lld\n",oule(av,n,m));
        //Out(Solve(1,av,m).fr);
        //cout<<oule(av,n,m)<<endl;
    }
    return 0;
}

