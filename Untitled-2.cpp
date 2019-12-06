#include <bits/stdc++.h>
using namespace std;
int h[10001] , n;
void swap(int x , int y)
{
    int tmp = h[x];
    h[x] = h[y];
    h[y] = tmp;
    return;
}
void siftdown(int i)
{
    int t , flag = 0;
    while(i*2 <= n && flag == 0)
    {
        if(h[i] > h[i*2])
        {
            t = i*2;
        }
        else
        {
            t = i;
        }
        if(i*2+1 <= n)
        {
            if(h[t] > h[i*2+1])
            {
                t = i*2+1;
            }
        }
        if(t != i)
        {
            swap(i , t);
            i = t;
        }
        else
        {
            flag = 1;
        }
    }
    return;
}
void creat()
{
    for(int i = n/2 ; i >= 1 ; i--)
    {
        siftdown(i);
    }
    return;
}
int deletemax()
{
    int t = h[1];
    h[1] = h[n];
    n--;
    siftdown(1);
    return t;
}
void heapsort()//最大堆
{
    while(n > 1)
    {
        swap(1 , n);
        n--;
        siftdown(1);
    }
    return;
}
int main()
{
    int num;
    scanf("%d" , &num);
    for(int i = 1 ; i <= num ; i++)
    {
        scanf("%d" , &h[i]);
    }
    n = num;
    creat();
    heapsort();
    for(int i = 1 ; i <= num ; i++)
    {
        printf("%d " , h[i]);
    }
    return 0;
}