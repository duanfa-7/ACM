#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , k , num = 1;
    string str;
    scanf("%d %d" , &n , &k);
    cin >> str;
    if(n == 1 && k != 0) printf("0\n");
    else if(k == 0) cout << str<<endl;
    else
    {
        for(int i = 0 ; i <= n ; i++)
        {
           if(i == 0) 
           {
               if(str[i] != '1')
               {
                    str[i] = '1';
                    num++;
               } 
           }
           else
           {
               if(str[i] != '0')
               {
                    str[i] = '0';
                    num++;
               } 
           }
           if(num > k) break;
        }
        cout << str <<endl;
    }
    return 0;
}