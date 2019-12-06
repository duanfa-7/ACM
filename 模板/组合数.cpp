//  n--64   m--33 以内的组合数
int c[maxn][maxn];
void solve()
{
    c[0][0] = c[1][1] = c[1][0] = 1;
    for(int i = 2 ; i <= maxn ; i++)
    {
        c[i][0] = 1;
        for(int j = 1 ; j <= maxn ; j++)
        {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
}