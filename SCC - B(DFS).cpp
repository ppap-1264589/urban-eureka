#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "B"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define base                    311
#define pii                     pair<int, int>
#define f                       first
#define s                       second
#define pb                      push_back
#define ep                      emplace_back
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
int n,m;
vector<int> a[maxn];
int f[maxn];

void add(int& a, int b){
    a = a + b;
    if (a >= MOD) a -= MOD;
}

int DFS(int u){
    if (f[u] != -1) return f[u];
    f[u] = 0;
    for (int v : a[u]){
        add(f[u], DFS(v) + 1);
    }
    return f[u];
}


signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    up(i, 1, m){
        int u,v;
        cin >> u >> v;
        a[u].ep(v);
    }

    fill(f, f+n+1, -1);
    up(i, 1, n){
        f[i] = DFS(i);
    }

    int res = 0;

    up(i, 1, n) add(res, f[i]);
    cout << res;

    ///debug
//    cout << "\n";
//    up(i, 1, n) cout << f[i] << " ";
    return 0;
}
