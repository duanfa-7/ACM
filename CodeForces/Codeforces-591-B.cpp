#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    string str1 , str2;
    scanf("%d" , &q);
    while(q--)
    {
        int flag = 0;
        cin >> str1 >> str2;
        int n = str1.length();
       for(int i = 0 ; i < n ;i++)
       {
           for(int j = 0 ; j < n ; j++)
           {
               if(str1[i] == str2[j])
               {
                   flag = 1;
                   break;
               }
           }
           if(flag) break;
       }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}