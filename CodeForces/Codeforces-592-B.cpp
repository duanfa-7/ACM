#include <bits/stdc++.h>
using namespace std;
int main()
{
     int t , n;
     string str;
     scanf("%d" , &t);
     while(t--)
     {
         scanf("%d" , &n);
         int x = -1 , y=-1;
         cin >> str;
         for(int i = 0 ; i < str.length() ; i++)
         {
             if(str[i] == '1') 
             {
                 x = i;
                 break;
             }
         }
        for(int i = str.length()-1 ; i >= 0 ; i--)
        {
            if(str[i] == '1') 
            {
                y = i;
                break;
            }
        }
        if(x==-1&&y==-1) printf("%d\n" , n);
        else
        {
            int ans = max(y+1,n-x) *2;
            printf("%d\n",ans);
        }
     }
    return 0;
}