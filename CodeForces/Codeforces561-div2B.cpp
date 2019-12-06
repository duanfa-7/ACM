#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
string str;
int solve(int n)
{
    int count = 5;
    while(count < n)
    {
        if(n % count == 0)
        {
        	if(n/count < 5)
        	{
        		return -1;
			}
            return count;
        }
        else
        {
            count++;
        }
    }
    return -1;
}
int main()
{
    int k;
	str = "aeiou"; 
    scanf("%d" , &k);
    if(k < 25 || solve(k) == -1)
    {
        printf("-1\n");
    }
    else
    {
        int x = solve(k);
        int y = k/x;
        for(int i = 0 ; i < x ; i ++)
        {
        	for(int j = 0 ; j < y ; j++)
        	{
        		cout << str[(i+j)%5];
			}
		}
    }
    return 0;
}