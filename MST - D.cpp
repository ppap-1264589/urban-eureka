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

const int maxn = 1001;
struct edge{
    int u,v,w;
};
vector<edge> E;
int n,m;
int par[maxn];
int res;
vector<pair<int, int>> E1;

int root(int u){
    if (par[u] == 0) return u;
    int x = root(par[u]);
    par[u] = x;
    return x;
}

bool Union(int u, int v){
    u = root(u);
    v = root(v);
    if (u != v){
        par[v] = u;
        return true;
    }
    return false;
}

bool cmp(edge& x, edge& y){
    return (x.w < y.w);
}

void Kruskal(){
    for (auto e : E){
        int u = e.u;
        int v = e.v;
        int w = e.w;
        if (Union(u, v)){
            res += w;
            E1.pb({u, v});
        }
    }
    cout << res << " ";
}

int Kruskal2(int uu, int vv){
    memset(par, 0, sizeof(par));

    int cost = 0;
    for (auto e : E){
        int u = e.u;
        int v = e.v;
        int w = e.w;
        if (u == uu && v == vv) continue;
        if (Union(u, v)){
            cost += w;
        }
    }
    set<int> checker;
    up(i, 1, n) checker.insert(root(i));
    if (checker.size() > 1) return INT_MAX;
    return cost;
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n >> m;
    int u,v,w;
    up(i, 1, m){
        cin >> u >> v >> w;
        E.pb({u, v, w});
    }

    sort(E.begin(), E.end(), cmp);
    Kruskal();

    res = INT_MAX;
    for (pii x : E1){
        res = min(res, Kruskal2(x.f, x.s));
    }
    cout << res;

//    cout << "\n";
//    for (int i = 1; i <= n; i++) cout << par[i] << " ";
    return 0;
}
