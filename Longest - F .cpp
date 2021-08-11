#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#define up(i, a, b) for (int i = (a); i <= (b); i++)
#define MOD 1000000007
#define pii pair<int, int>
#define s first
#define f second
using namespace std;

const int oo = INT_MAX;
const int maxn = 100001;
int n;
pii a[maxn];
int b[maxn];
int Tl[maxn*4];
int Tr[maxn*4];

void in(){
    cin >> n;
    up(i, 1, n){
        cin >> a[i].s >> a[i].f;
        b[i] = a[i].f;
    }
}

bool cmp(const pii& x, const pii& y){
    if (x.s == y.s) return (x.f < y.f);
    return (x.s < y.s);
}

void update(int nod, int l, int r, int u, int v, int val, int T[]){
    if (r < u || l > v) return;
    if (l >= u && r <= v){
        T[nod] = max(T[nod], val);
        return;
    }

    int mid = (l+r)/2;
    update(nod*2, l, mid, u, v, val, T);
    update(nod*2+1, mid+1, r, u, v, val, T);
    T[nod] = max(T[nod*2], T[nod*2+1]);
}

long long getmax(int nod, int l, int r, int u, int v, int T[]){
    if (r < u || l > v) return -oo;
    if (l >= u && r <= v){
        return T[nod];
    }

    int mid = (l+r)/2;
    int left = getmax(nod*2, l, mid, u, v, T);
    int right = getmax(nod*2+1, mid+1, r, u, v, T);
    return max(left, right);
}

int dp[maxn];
signed main(){
    if (fopen("A.inp", "r")){
        freopen ("A.inp", "r", stdin);
        freopen ("A.out", "w", stdout);
    }

    in();
    sort(a+1, a+n+1, cmp);
    sort(b+1, b+n+1);

    int MAXFJ = 0;
    int res = -oo;

    fill(Tl, Tl+maxn*4, -oo);
    fill(Tr, Tr+maxn*4, -oo);
    up(i, 1, n){
        int start = a[i].s;
        int finish = a[i].f;

        int k = lower_bound(b+1, b+n+1, start) - b;
        MAXFJ = getmax(1, 1, n, 1, k-1, Tl);

        if (MAXFJ < 0) MAXFJ = 0;
        dp[i] = max(dp[i], MAXFJ + finish - start);

        MAXFJ = getmax(1, 1, n, k, n, Tr);
        dp[i] = max(dp[i], MAXFJ + finish + start);

        k = lower_bound(b+1, b+n+1, finish) - b;
        update(1, 1, n, k, k, dp[i], Tl);
        update(1, 1, n, k, k, dp[i] - 2*finish, Tr);
        res = max(res, dp[i]);
    }
    cout << res;
}

//https://ideone.com/Xu5lWF