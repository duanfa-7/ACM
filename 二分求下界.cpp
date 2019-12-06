//��һҳ�Ǵ����룬���Ƶ�����������鿴Ч������

#include <iostream>

using namespace std;

/** �ǵݹ�д���������½�
 *
 * int *a �Ǵ��������
 * int l �����
 * int r ���ұ�
 * int v ��Ҫ����λ�õ�ֵ
 * ���ص����ҵ���λ���±�
 *
 */
int lowerBound(int *a, int l, int r, int v)
{
    int m;
    while(l < r)
    {
        m = l + (r-l)/2;//�� m = (l+r)/2;һ��
        if(v <= a[m])//if�жϾ��Ǹ������������д��
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
 * �ݹ�д���������½�
 * ���κ͵ݹ�һ��
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

