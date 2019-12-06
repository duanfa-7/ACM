#include<iostream>
#include<map>
#include<algorithm>
#define lson rt << 1
#define rson rt << 1|1
using namespace std;
const int MAXN = 1e5 + 5;

struct node{
    int l, r;
};

node pic[MAXN];
int change[MAXN];
map<int, bool> via;
int cnt, tol;
int Max[MAXN << 2];
int Set[MAXN << 2];

void pushUp(int rt){
    Max[rt] = max(Max[lson], Max[rson]);
}

void pushDown(int rt){
    if(!Set[rt]){
        return;
    }
    Set[lson] = Set[rson] = Set[rt];
    Max[lson] = Set[rt];
    Max[rson] = Set[rt];
    Set[rt] = 0;
}

void build(int l, int r, int rt){
    Set[rt] = Max[rt] = 0;
    if(l == r){
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, lson);
    build(m + 1, r, rson);
}

void upData(int L, int R, int k, int l, int r, int rt){
    if(L <= l && r <= R){
        Set[rt] = Max[rt] = k;
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if(L <= m){
        upData(L, R, k, l, m, lson);
    }
    if(m < R){
        upData(L, R, k, m + 1, r, rson);
    }
    pushUp(rt);
}

void Find(int l, int r, int rt){
    if(l == r){
        if(via[Max[rt]] != true && Max[rt] != 0){
            tol++;
            via[Max[rt]] = true;
        }
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    Find(l, m, lson);
    Find(m + 1, r, rson);
    pushUp(rt);
}

void init(){
    cnt = tol = 0;
    via.clear();
}

int main(){
    int T;
    cin >> T;
    while(T--){
        init();
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> pic[i].l >> pic[i].r;
            change[cnt++] = pic[i].l;
            change[cnt++] = pic[i].r;
        }
        sort(change, change + cnt);
        cnt = unique(change, change + cnt) - change;
        build(1, cnt, 1);
        for(int i = 1; i <= n; i++){
            int L = lower_bound(change, change + cnt, pic[i].l) - change + 1;
            int R = lower_bound(change, change + cnt, pic[i].r) - change + 1;
            upData(L, R, i, 1, cnt, 1);
        }
        Find(1, cnt, 1);
        cout << tol << endl;
    }
    return 0;
}

