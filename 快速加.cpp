long long quickplus(int m, int n, int k)
{
    long long res = 0;
    while (n > 0)
    {
        if (n & 1)
            res = (res + m) % k;
        m = (m + m) % k;
        n = n >> 1;
    }
    return res;
}
