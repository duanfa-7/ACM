#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int mod;
namespace io 
{
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () 
	{
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
// putchar
	inline void putc (char x) 
	{
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	inline bool read (signed &x) 
	{
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) 
	{
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) 
	{
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x)
	{
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y)
	{
		return read(x)&&read(y...);
	}
	// print a signed integer
	inline bool write (signed x) 
	{
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) 
	{
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) 
	{
		putc(x);
		return 0;
	}
	inline bool write(const char *x)
	{
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x)
	{
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y)
	{
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
namespace FFFFFT
{
    typedef complex<db> E;
    const db pi = acos(-1.0);
    const int N = 1 << 17, L = 16, mask = (1 << L) - 1;
    E w[N];
    void INIT()
    {
        for(int i = 0; i < N; i++)
            w[i] = E(cos(2.0 * i * pi / N), sin(2.0 * i * pi / N));
    }
    void FFT(E p[], int n)
    {
        for(int i = 1, j = 0; i < n - 1; i++)
        {
            for(int s = n; j ^= s >>= 1, ~j & s;);
            if(i < j) swap(p[i], p[j]);
        }
        for(int d = 0; (1 << d) < n; d++)
        {
            int m = 1 << d, m2 = m * 2, rm = n >> (d + 1);
            for(int i = 0; i < n; i += m2)
            {
                for(int j = 0; j < m; j++)
                {
                    E &p1 = p[i+j+m], &p2 = p[i+j];
                    E t = w[rm*j]*p1;
                    p1 = p2 - t, p2 = p2 + t;
                }
            }
        }
    }
    E A[N], B[N], C[N], D[N];
    void mul(int a[N], int b[N])
    {
        for(int i = 0; i < N; i++)
        {
            A[i] = E(a[i] >> L, a[i] & mask);
            B[i] = E(b[i] >> L, b[i] & mask);
        }
        FFT(A,N); FFT(B, N);
        for(int i = 0; i < N; i++)
        {
            int j = (N - i) % N;
            E da = (A[i] - conj(A[j])) * E(0, -0.5);
            E db = (A[i] + conj(A[j])) * E(0.5, 0);
            E dc = (B[i] - conj(B[j])) * E(0, -0.5);
            E dd = (B[i] + conj(B[j])) * E(0.5, 0);
            C[j] = da * dd + da * dc * E(0,1);
            D[j] = db * dd + db * dc * E(0,1);
        }
        FFT(C,N); FFT(D,N);
        for(int i = 0; i < N; i++)
        {
            ll da = (ll)(C[i].imag() / N + 0.5) % mod;
            ll db = (ll)(C[i].real() / N + 0.5) % mod;
            ll dc = (ll)(D[i].imag() / N + 0.5) % mod;
            ll dd = (ll)(D[i].real() / N + 0.5) % mod;
            a[i] = ((dd << (L * 2)) + ((db + dc) << L) + da) % mod;
        }
    }

}

ll pm(ll a, ll b)
{
    ll re = 1;
    while(b)
    {
        if(b&1) re = re * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return re;
}
ll inv[150005], pw[150005];
int a[FFFFFT::N], b[FFFFFT::N];
unordered_map <ll, ll> mp;
void work(int m, int n)
{
    memset(a, 0, sizeof a);
    for(int k = 0; k <= n; k++)
    {
        a[k] = inv[k];
        if(k & 1) a[k] = (mod - a[k]) % mod;
    }
    for(int k = 0; k <= n; k++)
        b[k] = pm(k, m) * inv[k] % mod;
}
ll P(int m, int n)
{
    if(mp.count(100000ll * m + n))
        return pw[n] * mp[100000ll * m + n] % mod;
    ll re = 0;
    for(int k = 0; k <= n; k++)
    {
        ll tmp = pm(n - k, m) * inv[k] % mod * inv[n - k] % mod;
        if(k & 1) tmp = -tmp;
        re += tmp;
    }
    re = (re % mod + mod) % mod;
    return pw[n] * re % mod;
}
void INIT(int n, int P)
{
    int i;
    for(inv[0] = inv[1] = 1, i = 2; i <= n; i++)
    {
        inv[i] = -inv[P % i] * (P / i) % P;
        while(inv[i] < 0) inv[i] += P;
    }
    for(pw[0] = 1, i = 1; i <= n; i++)
    {
        pw[i] = pw[i - 1] * i % P;
        inv[i] = inv[i - 1] * inv[i] % P;
    }
}
int n, m;
using io :: read;
using io :: putc;
using io :: write;
int main()
{
    FFFFFT::INIT(); int t;
    read(t);
    for(int i = 1; i <= t; i++)
    {
        mp.clear();
        read(n);
        read(m);
        read(mod);
        INIT(n + m + 1, mod);
        ll ans = 0;
        if(n > 600 || m > 600)
        {
            work(n, min(n, m) + 1);
            FFFFFT::mul(a, b);
            for(int k = 0; k <= min(n, m) + 1; k++)
                mp[100000ll * n + k] = a[k];
            work(m, min(n, m) + 1);
            FFFFFT::mul(a, b);
            for(int k = 0; k <= min(n, m) + 1; k++)
                mp[100000ll * m + k] = a[k];
        }
        for(int k = 1; k <= min(n, m) + 1; k++)
            ans = (ans + (P(n, k) + P(n, k - 1)) * (P(m, k) + P(m, k - 1))) % mod;
        printf("Case #%d: %lld\n", i, ans);
    }
}
