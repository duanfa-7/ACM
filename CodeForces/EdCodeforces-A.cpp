#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t , n , cnt;
    string num;
    scanf("%d" , &t);
    while(t--)
    {
        cnt = -1;
        scanf("%d" , &n);
        cin >> num;
        if(n < 11)
        {
            printf("NO\n");
        }
        else if(n == 11)
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(num[i] == '8')
                {
                    cnt = i;
                    break;
                }
            }
            if(cnt == 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(num[i] == '8')
                {
                    cnt = i;
                    break;
                }
            }
            if(cnt == -1)
            {
                printf("NO\n");
            }
            else if((n-11) >= cnt && cnt != -1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}