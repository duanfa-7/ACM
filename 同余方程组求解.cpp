int main()
{
    int n;scanf("%d",&n);n--;
    ll b1,m1;scanf("%lld%lld",&b1,&m1);b1=b1%m1;
    ll XX;
    while(n--)
    {
        ll b2,m2;scanf("%lld%lld",&b2,&m2);b2=b2%m2;
        ll A=m1,B=m2,K=b2-b1;
        ll x,y;
        ll d=ExEuclid(A,B,x,y);
        if(K%d!=0)
        {
            printf("no solution!");
            return 0;
        }
        else
        {
            x=x*K/d;
            ll t=B/d;XX=(x%t+t)%t;
            b1=m1*XX+b1;
            m1=A*B/d;//LCM(m1,m2)=LCM(A,B)
        }
    }
    
    printf("%lld",b1);
}
