#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    return n*(n-1) / 2;
}
int main()
{
    map<char , int> M;
    int t;
    char str[100];
    scanf("%d" , &t);
    while(t--)
    {
        cin >> str;
        M[str[0]]++;
    }
    int ans = 0;
    for(char i = 'a' ; i <= 'z' ; i++)
    {
        int num = M[i];
        int op = num / 2;
        if(num % 2 == 1)
        {
            ans += solve(op+1);
            ans += solve(op);
        }
        else
        {
            ans += solve(op);
            ans += solve(op);
        }
    }
    printf("%d\n" , ans);
    return 0;
}