#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , cnt;
    string str , str1;
    scanf("%d" , &n);
    cin >> str;
    int t = 0;
    cnt = 0;
    while(t < n)
    {
        if(str[t] != str[t+1] && (t+1) < n)
        { 
            str1 += str[t];
            str1 += str[t+1];
            t += 2;
        }
        else
        {
            cnt++;
            t++;
        }
    }
    if(cnt == n)
    {
        printf("%d\n" , cnt);
        cout << endl;
    }
    else
    {
        printf("%d\n" , cnt);
        cout << str1<<endl;
    }
    
    return 0;
}