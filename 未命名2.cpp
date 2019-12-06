#include <iostream>
#include <algorithm>
#include<stdio.h> 
using namespace std;
typedef long long LL;
const int N = 401000;
int primes[N], euler[N], cnt;
bool st[N];
void get_eulers(int n)
{
    for (int i = 2; i <= n-1; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
for (int j = 0; j < cnt && i * primes[j] <= n-1; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                euler[i * primes[j]] = euler[i] * primes[j];
                break;
            }
            euler[i * primes[j]] = euler[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    int  n;
    get_eulers(N - 1);
        cin >> n;
        int res = 0;
        for (int i = 2; i <= n-1; i ++ ) res += euler[i];
        printf("%d\n",res * 2 + 3);
    return 0;
} 
