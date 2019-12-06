#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6+90;
ll num[maxn] , xx[maxn] , yy[maxn];
ll ans1 , ans2;
int main()
{
    string str;
    ll a , b;
    ll cnt;
    ans1 = 0;
    cin >> str;
    cin >> a >> b;
    memset(yy , -1 , sizeof(yy));
    int len = str.length();
    for(int i = 0 ; i < len ; i++)
    {
        num[i+1] = (str[i]-'0');
    }
    for(int i = 1 ; i < len ; i++)
    {
        ans1 = (ans1*10+num[i])%a;
        xx[i] = ans1;
    }
    ll tmp = 1;
    for(int i = len; i > 1 ; i--)
    {
        if(num[i]==0) yy[i-1]=-1;
        else
        {
            ans2 = (ans2 + num[i]*tmp)%b;
            yy[i-1] = ans2;
        }    
        tmp = (tmp*10)%b;
    }
    // for(int i = 1 ; i < len ; i++)
    // {
    //     cout<<"xx[i] = " << xx[i] << endl;
    //     cout<<"yy[i] = " << yy[i] << endl;
    // }
    int flag = 0;
    for(int i = len ; i >= 1;i--)
    {
        if(xx[i]== 0 && yy[i] == 0)
        {
        //    printf("xx[%d]= %lld yy = %lld" , i ,xx[i] , yy[i]);
            flag = 1;
            cnt = i;
            break;
        }
    }
    if(flag)
    {
        printf("YES\n");
        for(int i = 1 ; i <= cnt ; i++)
        {
            cout << num[i];
        }
        cout << endl;
        for(int i = cnt+1 ; i <= len ; i++)
        {
            cout << num[i];
        }
        cout << endl;
    }
   else
   {
       printf("NO\n");
   }
    return 0;
}