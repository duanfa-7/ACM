#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+8;
int a[maxn] , b[maxn];
int main()
{
    int n , x , y , cnt = 0;
    string str;
    scanf("%d %d %d" , &n , &x , &y);
    cin >> str;
    int t = 0;
    for(int i = n-1 ; i >= 0 ; i--)
    {
        b[t++] = str[i]-'0';
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(i == x || i == y)
        {
            a[i] = 1;
        }
    }
    for(int i = 0 ; i < x ; i++)
    {
    //	printf("a[i] = %d b[i] = %d\n" , a[i] , b[i]); 
        if(a[i] ^ b[i] != 0)
        {
            cnt++;
        }
    }
    printf("%d\n" , cnt);
    return 0;
}