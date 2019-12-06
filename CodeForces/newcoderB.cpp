#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[600];
map<int , string>M;
string str[600];
void init()
{
    M[0].insert("coffee") ;
    M[1].insert("chickeen") ;
    for(int i = 2 ; i <= 500 ; i++)
    {
        M[i].insert(M[i-1]);
        M[i].insert(M[i-2]);
    }
}
int main()
{
   int t , n , k;
   scanf("%d" , &t);
   init();
   while(t--)
   {
       scanf("%d %d" , &n , &k);
       int len =M[n].size();
       if(k+10 <= len)
       {
           for(int i = k ; i <= k+10 ; i++)
           {
               cout<<M[n][i];
           }
       }
       else
       {
           for(int i = k ; i < len ; i++)
           {
               cout << M[n][i];
           }
       }
   }
    return 0;
}