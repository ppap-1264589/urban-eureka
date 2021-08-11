#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task            "A"                                 ///map of knowledge
#define ll              long long                           //+ Binary Lifting
#define bit(x,i)        ((x >> i) & 1)                      //+ Hash Table
#define stt(x,i)        (x & (1 << i))                      //+ Trie Tree
#define trail0(x)       (x & (-x))                          //+ Sparse Table - RMQ
#define up(i,a,b)       for (int i = (a); i <= (b); i++)    //+ Matrix
#define down(i,a,b)     for (int i = (a); i >= (b); i--)    //+ DSU
#define MOD             1000000007                          //+ Joints - Bridges
#define base            311                                 //+ SCC
#define pii             pair<int, int>                      //+ Z-KMP
#define f               first
#define s               second
#define pb              push_back
#define ep              emplace_back
using namespace std;

const int maxn = 100001;
int n, root, m;
vector<int> a[maxn];
int h[maxn];
int par[maxn][18];

void in(){
    cin >> n >> root >> m;
    int u,v;
    up(i, 1, n-1){
        cin >> u >> v;
        a[u].ep(v);
        a[v].ep(u);
    }
}

int tdfs;
void DFS(int u){
    for (int v : a[u]){
        if (v != par[u][0]){
            h[v] = ++tdfs;
            par[v][0] = u;
            up(i, 1, 17){
                par[v][i] = par[par[v][i-1]][i-1];
            }
            DFS(v);
            tdfs--;
        }
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];
    for (int i = 0; i <= 17; i++){
        if (bit(delta, i)) u = par[u][i];
    }

    if (u == v) return u;

    down(i, 17, 0){
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    in();
    DFS(root);

    int u,v;
    while (m--){
        cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
    return 0;
}