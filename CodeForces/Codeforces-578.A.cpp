#include <bits/stdc++.h>
using namespace std;
int a[20];
int book[20];
int main()
{
    int n;
    string str;
    memset(a , 0 , sizeof(a));
    scanf("%d" , &n);
    cin >> str;
    int len = str.length();
    for(int i = 0 ; i < len ; i++)
    {
        if(str[i] == 'L') 
        {
           for(int j = 0 ; j <= 9 ; j++)
            {
                if(book[j] == 0)
                {
                    a[j] = 1;
                    book[j] = 1;
                    break;
                }
            }
        }
        else if(str[i] == 'R') 
        {  
            for(int j = 9 ; j >= 0 ; j--)
            {
                if(book[j] == 0)
                {
                    a[j] = 1;
                    book[j] = 1;
                    break;
                }
            }
        }
        else
        {
            int op = str[i]-'0';
            a[op] = 0;
           book[op] = 0;
        }
        
    }
    for(int i = 0 ; i <= 9 ; i++)
    {
        printf("%d" , a[i]);
    }
    cout << endl;
    return 0;
}