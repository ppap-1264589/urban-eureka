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
using namespace std;

const int maxn = 100001;
int n,m;
vector<pii> a[maxn];
int dist[maxn];
int connect[maxn];
long long ans = 0;
bool d[maxn];
int canh = 0;
///distance

void Push(int u){
    d[u] = 1;
    for (pii x : a[u]){
        int v = x.f;
        int w = x.s;
        if (!d[v] && dist[v] > w){
            dist[v] = w;
            connect[v] = u; /// Truy vet
        }
    }
}

void Prim(int root){
    fill(dist, dist+n+1, INT_MAX);
    Push(root);
    dist[root] = 0;
    while (1){
        int u = 0;
        for (int i = 1; i <= n; i++){
            if (!d[i] && dist[u] > dist[i]) u = i;
        }
        if (u == 0) break;
        canh++;
        ans += dist[u];
        Push(u);
    }
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
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
    Prim(1);
    cout << ans;

    if (canh != n-1){
        cout << "-1";
        return;
    }
    for (int i = 2; i <= n; i++) cout << i << " " << connect[i] << "\n";
    return 0;
}
