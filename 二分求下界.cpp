//这一页是纯代码，复制到编译器里面查看效果更好

#include <iostream>

using namespace std;

/** 非递归写法二分求下界
 *
 * int *a 是传入的数组
 * int l 是左边
 * int r 是右边
 * int v 是要查找位置的值
 * 返回的是找到的位置下标
 *
 */
int lowerBound(int *a, int l, int r, int v)
{
    int m;
    while(l < r)
    {
        m = l + (r-l)/2;//和 m = (l+r)/2;一样
        if(v <= a[m])//if判断就是根据那三种情况写的
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

/**
 * 递归写法二分求下界
 * 传参和递归一样
*/

int lowerBoundRecursion(int *a, int l, int r, int v)
{
    if(l >= r)
        return l;
    int m = l + (r-l)/2;
    if(v <= a[m])
    {
        return lowerBoundRecursion(a,l,m,v);
    }
    return lowerBoundRecursion(a,m+1,r,v);

}

int main()
{
    int a[9] = {1,2,3,4,4,4,6,7,8};
    cout << lowerBound(a,0,9,4) << endl;
    cout << lowerBoundRecursion(a,0,9,4) << endl;
    return 0;
}

