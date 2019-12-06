#include <bits/stdc++.h>
#define ll long long
using namespace std;
char str[1005][1005];
int a[1005];
map<char, int>M;
int ans = 0 , sum = 0;
int main()
{
    int n , m;
    scanf("%d %d" , &n , &m);
   for(int i = 0 ; i < n ; i++)
   {
      scanf("%s" , &str[i]);
   }  
   for(int i = 0 ; i < m ; i++)
   {
       scanf("%d" , &a[i]);
   }
//   for(int i = 0 ; i < n ; i++)
//   {
//      for(int j = 0 ; j < m ; j++)
//      {
//         putchar(str[i][j]);
//      }
//   }  
   for(int i = 0 ; i < m ; i++)
   {
   		ans = 1; 
       for(int j = 0 ; j < n ; j++)
       {
           M[str[j][i]]++;
          ans = max(ans ,  M[str[j][i]]);
       }
       M.clear();
    sum += (ans *a[i]);
   }
    printf("%d\n" , sum);
    return 0;
}