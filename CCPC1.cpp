#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct SegmentTree{
    struct Node{
        int maxx, minn;
    };

    Node node[MAXN << 2];

    inline int lSon(int rt){
        return rt << 1;
    }

    inline int rSon(int rt){
        return rt << 1 | 1;
    }

    void pushUp(int rt){
        node[rt].maxx = max(node[lSon(rt)].maxx, node[rSon(rt)].maxx);
        node[rt].minn = min(node[lSon(rt)].minn, node[rSon(rt)].minn);
    }

    void build(int l, int r, int rt){
        node[rt].maxx = -inf;
        node[rt].minn = inf;
        if(l == r){
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, lSon(rt));
        build(m + 1, r, rSon(rt));
    }

    void upDate(int k, int v, int l, int r, int rt){
        if(l == r){
            node[rt].maxx = node[rt].minn = v;
            return;
        }
        int m = (l + r) >> 1;
        if(k <= m){
            upDate(k, v, l, m, lSon(rt));
        }else{
            upDate(k, v, m + 1, r, rSon(rt));
        }
        pushUp(rt);
    }

    int Max(int v, int l, int r, int rt){
        if(l == r){
            return node[rt].maxx > v ? l : inf;
        }
        int m = (l + r) >> 1;
        if(node[lSon(rt)].maxx > v){
            return Max(v, l, m, lSon(rt));
        }else if(node[rSon(rt)].maxx > v){
            return Max(v, m + 1, r, rSon(rt));
        }
        return inf;
    }

    int Max(int k, int v, int l, int r, int rt){
        if(l == r){
            return node[rt].maxx > v ? l : inf;
        }
        int m = (l + r) >> 1;
        if(k <= m && node[lSon(rt)].maxx > v){
            return min(Max(k, v, l, m, lSon(rt)), Max(v, m + 1, r, rSon(rt)));
        }else if(node[rSon(rt)].maxx > v){
            return Max(k, v, m + 1, r, rSon(rt));
        }
        return inf;
    }

    int Min(int v, int l, int r, int rt){
        if(l == r){
            return node[rt].minn <= v ? l : inf;
        }
        int m = (l + r) >> 1;
        if(node[lSon(rt)].minn <= v){
            return Min(v, l, m, lSon(rt));
        }else if(node[rSon(rt)].minn <= v){
            return Min(v, m + 1, r, rSon(rt));
        }
        return inf;
    }

    int Min(int k, int v, int l, int r, int rt){
        if(l == r){
            return node[rt].minn <= v ? l : inf;
        }
        int m = (l + r) >> 1;
        if(k <= m && node[lSon(rt)].minn <= v){
            return min(Min(k, v, l, m, lSon(rt)), Min(v, m + 1, r, rSon(rt)));
        }else if(node[rSon(rt)].minn <= v){
            return Min(k, v, m + 1, r, rSon(rt));
        }
        return inf;
    }
};

int n, q;
int a[MAXN];
SegmentTree tree, solve;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    scanf("%d" , &T);
    while(T--)
    {
       scanf("%d %d" , &n , &q);
        tree.build(1, n, 1);
        solve.build(1, n, 1);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d" , &a[i]);
            tree.upDate(a[i], i, 1, n, 1);
        }
        int res = 0;
        while(q--){
            int op, r, k;
           scanf("%d" , &op);
            if(op == 1){
                scanf("%d" , &k);
                k ^= res;
                solve.upDate(a[k], k, 1, n, 1);
            }
            else
            {
                scanf("%d %d" , &r , &k);
                r ^= res;
                k ^= res;
                res = min(tree.Max(k, r, 1, n, 1), solve.Min(k, r, 1, n, 1));
                if(res == inf)
                {
                    res = n + 1;
                }
                cout << res << endl;
            }
        }
    }
    return 0;
}
