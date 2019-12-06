#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+100;
int row[maxn] , col[maxn];
int up[maxn] , dw[maxn] , L[maxn] , R[maxn];
char sum[maxn][maxn];
int ans[maxn][maxn] , ans1[maxn][maxn];
int x , y,cnt;
int main()
{
    int n , k,flag;
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; i++) scanf("%s" , sum[i]+1);
    //预处理得到该行或列是否全为W , 以及非 全W时 ， 它的最左最右（最上最下）B的下标
    for(int i = 1 ; i <= n ; i++)
    {
        flag = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            if(sum[i][j] == 'B')
            {
                flag = 1;
                if(!L[i]) L[i] = j;//这一步怎么就没有想到呢 ， 好强哇
                R[i] = j;
            }
        }
        if(flag == 0) row[i] = 1,x++;

        flag = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            if(sum[j][i] == 'B')
            {
                flag = 1;
                if(!up[i])up[i] = j;
                dw[i] = j;
            }
        }
        if(flag == 0) col[i] = 1,y++;
    }
    //行的计算
    for(int i = 1 ; i+k-1 <= n ; i++)
    {
        for(int j = 1 ; j+k-1 <= n ; j++)
        {
            
            if(j == 1)
            {
                cnt = y;
                for(int c = 1 ; c <= k ; c++)
                {
                    if(col[c]) continue;
                    if(up[c]>=i&&dw[c]<=i+k-1) cnt++;
                    //这里不能用dw[c]-up[c]+1 <= k , 这个只能代表长度，要有限制在i~i+k-1之间
                }
                ans1[i][j] = cnt;
            }
            else
            {
                if(!col[j-1])
                {
                    if(up[j-1]>=i&&dw[j-1]<=i+k-1) cnt--;
                }
                if(!col[j+k-1])
                {
                    if(up[j+k-1]>=i&&dw[j+k-1]<=i+k-1) cnt++;
                }
                ans1[i][j] = cnt;
            }
        }
    }
    for(int j = 1 ; j+k-1 <= n ; j++)
    {
        for(int i = 1 ; i+k-1 <= n ; i++)
        {
            if(i == 1)
            {
                cnt = x;
                for(int c = 1 ; c <= k ; c++)
                {
                    if(row[c]) continue;
                    if(L[c]>=j&&R[c]<=j+k-1) cnt++;
                }
                ans[i][j] = cnt;
            }
            else
            {
                if(!row[i-1])
                {
                    if(L[i-1]>=j&&R[i-1]<=j+k-1) cnt--;
                }
                if(!row[i+k-1])
                {
                    if(L[i+k-1]>=j&&R[i+k-1]<=j+k-1) cnt++;
                }
                ans[i][j] = cnt;
            }
        }
    }
    int op = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            op = max(op , ans[i][j]+ans1[i][j]);
        }
    }
    printf("%d\n" , op);
    return 0;
}