#include <bits/stdc++.h>
using namespace std;
int main()
{
    int R , G , B , N;
    scanf("%d %d %d %d" , &R , &G , &B , &N);
    int ans = 0;
    for(int i = 0 ; i <= 3000 ; i++)
    {
        for(int j = 0 ; j <= 3000 ; j++)
        {
            if(N - (R*i + G*j) >= 0)
            {
                if( (N - (R*i + G*j)) % B == 0)
                {
                    ans++;
                }
            }
            
        }
    }
    printf("%d\n" , ans);
    return 0;
}