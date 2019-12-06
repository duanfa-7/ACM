// #include <bits/stdc++.h>
// #define lson l , m , rt<<1
// #define rson m+1 , r , rt<<1|1
// using namespace std;
// const int maxn = 2e5+10;
// int Sum[maxn<<2];
// void PushUp(int rt)
// {
//     Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
// }
// void Build(int l , int r , int rt)
// {
//     if(l == r)
//     {
//         scanf("%d" , &Sum[rt]);
//         return ;
//     }
//     int m = (l+r)/2;
//     Build(lson);
//     Build(rson);
//     PushUp(rt);
// }
// int main()
// {

//     return 0;
// }



////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int x[maxn] , y[maxn] , a[maxn] , cnt;
int main()
{
    int n , q , temp , b , c;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ;i++)
    {
        scanf("%d" , &a[i]);
    }   
    scanf("%d" , &q);
    cnt = 0;
    while(q--)
    {
        scanf("%d" , &temp);
        if(temp == 1)
        {
            scanf("%d %d" , &b , &c);
            a[b] = c;    //b这个点改为c；
            x[b] = cnt;  // b这个点在cnt这个时间被更新了
        }
        else
        {
            scanf("%d" , &b);     
            y[cnt] = b;   //cnt这个时间小于b的都更新为b
        }
        cnt++;//cnt次操作
    }
    for(int i = cnt-1 ; i >= 0 ; i--)
    {
        y[i] = max(y[i] , y[i+1]); // y[0]时更新的是所有2开头的最大的数
    }
    for(int i = 1 ; i <= n ; i++)
    {   //如果i这个点没有改变 x[i] = 0; 只需比较a[i]和y[0]的最大值
        printf("%d " , max(a[i] , y[x[i]]));//如果a[i]改变了 ， x[i]在这个顺序下被更新的最大值
    }
    return 0;
}