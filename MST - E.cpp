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

const int maxn = 501;
struct edge{
    int u,v,w;
};
vector<edge> E;
int par[maxn];
int n,m;
int dem;

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
        par[u] = v;
        return true;
    }
    return false;
}

bool cmp(edge& x, edge& y){
    return (x.w < y.w);
}

void Kruskal(){
    memset(par, 0, sizeof(par));

    int sum = 0;
    vector<edge> vt;
    for (edge e : E){
        int u = e.u;
        int v = e.v;
        int w = e.w;
        if (Union(u, v)){
            sum += w;
            vt.pb(e);
        }
    }
    E.assign(vt.begin(), vt.end());
    if ((int)E.size() != n-1) cout << -1;
    else cout << sum;
    cout << "\n";
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
    up(i, 1, m){
        int u,v,w;
        cin >> u >> v >> w;
        E.insert(E.begin(), {u, v, w});
        for (int i = 0; i < (int)E.size()-1; i++){
            if (E[i].w > E[i+1].w) swap(E[i], E[i+1]);
            else break;
        } // Optimize algorithm by Insertion sort
        Kruskal();
    }

    return 0;
}
