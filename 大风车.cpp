#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
char a[150][150];
void init(int x)
{
    for(int i = 0 ; i < 2*x-1 ; i++)
    {
        for(int j = 0 ; j < 2*x-1 ; j++)
        {
            a[i][j] = '*';
        }
    }
}
int main()
{
    int n;
    while(cin >> n)
    {
        init(n);
        for(int i = n-2 ; i >= 0 ; i--)
        {
            for(int j = i-1 ; j >= 0 ; j--)
            {
                if(a[i][j] == '*')
                {
                    a[i][j] = ' ';
                }
            }
        }
        for(int i = n-2 ; i >= 0 ; i--)
        {
            for(int j = n ; j < 2*n-2-i; j++)
            {
                if(a[i][j] == '*')
                {
                    a[i][j] = ' ';
                }
            }
        }
        for(int i = n ; i <= 2*n-2 ; i++)
        {
            for(int j = i+1 ; j <= 2*n-1; j++)
            {
                if(a[i][j] == '*')
                {
                    a[i][j] = ' ';
                }
            }
        }
        for(int i = 2*n-2; i > n ; i--)
        {
            for(int j = 2*n-i-1 ; j < n-1; j++)
            {
                if(a[i][j] == '*')
                {
                    a[i][j] = ' ';
                }
            }
        }
        for(int i = 0 ; i < 2 * n - 1 ; i++)
        {
            for(int j = 0 ; j < 2*n-1 ; j++)
            {
                cout <<a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
