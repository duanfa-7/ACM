/*
���⣺
    ��n��ţ����ѡm���Ž�ţ���൱��һ���߶����� n ���㣬ѡȡ m ���㣬
ʹ�����ڵ�֮�����С����ֵ���
˼·��̰��+����
    ����ö��������ţ�ļ�࣬�жϴ��ڵ��ڴ˼�����ܷ�Ž����е�ţ��
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e6+10;
int a[N],n,m;
bool judge(int k)//ö�ټ��k�����ܷ�ʹ����������ţ
{
    int cnt = a[0], num = 1;//numΪ1��ʾ�Ѿ���һͷţ����a[0]ţ����
    for(int i = 1; i < n; i ++)//ö��ʣ�µ�ţ��
    {
        if(a[i] - cnt >= k)//a[i]���ţ������һ��ţ�������ڵ���k����ʾ�����ٷŽ�ţ
        {
            cnt = a[i];
            num ++;//�ַŽ���һͷţ
        }
        if(num >= m) return true;//����ţ��������
    }
    return false;
}
void solve()
{
    int l = 1, r = a[n-1] - a[0];//��С����Ϊ1��������Ϊţ��������ļ�ȥ�����С��
    while(l < r)
    {
        int mid = (l+r) >> 1;
        if(judge(mid)) l = mid + 1;
        else r = mid;
    }
    printf("%d\n",r-1);
}
int main()
{
    int i;
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 0; i < n; i ++)
            scanf("%d",&a[i]);
        sort(a, a+n);//��ţ������
        solve();
    }
    return 0;
}

