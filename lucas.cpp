#include <iostream>
#include <stdio.h>
#include <algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

ll mulit(ll a,ll b,ll m){
    ll ans=0;
    while(b){
        if(b&1) ans=(ans+a)%m;
        a=(a<<1)%m;
        b>>=1;
    }
    return ans;
}

ll quick_mod(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans=mulit(ans,a,m);
        }
        a=mulit(a,a,m);
        b>>=1;
    }
    return ans;
}

ll comp(ll a,ll b,ll m){
    if(a<b) return 0;
    if(a==b) return 1;
    if(b>a-b) b=a-b;
    ll ans=1,ca=1,cb=1;
    for(int i=0;i<b;i++){
        ca=ca*(a-i)%m;
        cb=cb*(b-i)%m;
    }
    ans=ca*quick_mod(cb,m-2,m)%m;
    return ans;
}

ll lucas(ll a,ll b,ll m){
    ll ans=1;
    while(a&&b){
        ans=(ans*comp(a%m,b%m,m))%m;
        a/=m;
        b/=m;
    }
    return ans;
}

int main()
{
    ll a,b,m;
    while(cin>>a>>b>>m){
        cout<<lucas(a,b,m)<<endl;
    }
    return 0;
}