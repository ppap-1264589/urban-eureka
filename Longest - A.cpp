#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task            "A"                                  /// map of knowledge
#define bit(x, i)       ((x >> i) & 1)                       //+ Binary Lifting
#define trail0(x)       (x & (-x))                           //+ Hash Table
#define up(i,a,b)       for (int i = (a); i <= (b); i++)     //+ Retrieval Tree
#define down(i,a,b)     for (int i = (a); i >= (b); i--)     //+ Sparse Table - RMQ
#define MOD             1000000007                           //+ Matrix
#define base            311                                  //+ DSU
#define pii             pair<int, int>                       //+ Joints - Bridges
#define f               first                                //+ SCC
#define s               second                               //+ Z-KMP
#define pb              push_back                            //+ MST
#define ep              emplace_back                         //+ LCA
#define MAX_ARR_SIZE    486010000                            //+ Shortest Path
                                                             //+ Fenwick Tree
                                                             //+ Segment Tree
                                                             //+ DP Mask
using namespace std;

const int maxn = 100001;
int d[maxn];
vector<pii> a[maxn];
int n;

void in(){
    cin >> n;
    int u,v,w;
    up(i, 1, n-1){
        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
}

void DFS(int u, int par){
    for (pii x : a[u]){
        int v = x.f;
        int w = x.s;
        if (v == par) continue;

        d[v] = d[u] + w;
        DFS(v, u);
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    in();
    DFS(1, -1);
    int x = max_element(d+1, d+n+1) - d;
    memset(d, 0, sizeof(d));
    DFS(x, -1);
    cout << *max_element(d+1, d+n+1);
    return 0;
}
