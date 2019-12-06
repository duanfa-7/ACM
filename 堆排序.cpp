#include <stdio.h>
#include <iostream>
using namespace std;
int h[101] , n;

void swap(int x , int y)//交换堆中俩个元素的值
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
    return;
}
void siftdown(int i)
{
    int t , flag = 0;//flag用来标记是否需要向下调整
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
            swap(t,i);
            i = t;
        }
        else
        {
            flag = 1;
        }
    }
    return;
}
//建立堆的函数
void creat()
{
    for(int i = n/2 ; i >= 1 ; i--)
    {
        siftdown(i);
    }
    return;
}
//删除最大的元素
int deletemax()
{
    int t;
    t = h[1];//用一个临时变量记录堆顶点的值
    h[1] = h[n];//将堆的最后一个点的值赋给堆顶
    n--;//堆的元素减少1
    siftdown(1);//向下调整
    return t;
}
void heapsort()//堆排序  原数组  从大到小
{
    while(n>1)
    {
        swap(1,n);
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
    creat();//建堆
    //删除顶部元素 ， 连续删除n次 ， 也就是从大到小把数输出来

    //heapsort();
    for(int i = 1 ; i <= num ; i++)
    {
        printf("%d " , deletemax());//printf("%d " , h[i]);
    }
    return 0;
}
