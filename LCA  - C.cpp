#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task            "A"                                  ///map of knowledge
#define bit(x, i)       ((x >> i) & 1)                       //+ Binary Lifting
#define trail0(x)       (x & (-x))                           //+ Hash Table
#define up(i,a,b)       for (int i = (a); i <= (b); i++)     //+ Trie Tree
#define down(i,a,b)     for (int i = (a); i >= (b); i--)     //+ Sparse Table - RMQ
#define MOD             1000000007                           //+ Matrix
#define base            311                                  //+ DSU
#define pii             pair<int, int>                       //+ Joints - Bridges
#define f               first                                //+ SCC
#define s               second                               //+ Z-KMP
#define pb              push_back                            //+ MST
#define ep              emplace_back                         //+ LCA
using namespace std;

const int maxn = 100001;
int par[maxn][18];
int h[maxn];
int mpar[maxn][18];
int n,m;
struct edge{
    int u,v,w;
};
edge E[maxn];
int P[maxn];
bool dd[maxn];
vector<pii> a[maxn];

void in(){
    cin >> n >> m;
    up(i, 1, m){
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
}

bool cmp(edge& x, edge& y){
    return (x.w > y.w);
}

int root(int u){
    if (P[u] == 0) return u;
    int x = root(P[u]);
    P[u] = x;
    return x;
}

bool Union(int u, int v){
    u = root(u);
    v = root(v);
    if (u != v){
        P[u] = v;
        return true;
    }
    return false;
}

void mark_MST(){
    sort(E+1, E+m+1, cmp);
    up(i, 1, m){
        int u = E[i].u;
        int v = E[i].v;
        int w = E[i].w;
        if (Union(u, v)){
            dd[i] = true;
            a[u].pb({v, w});
            a[v].pb({u, w});
        }
    }
}

void DFS(int u){
    for (pii x : a[u]){
        int v = x.f;
        int w = x.s;
        if (v != par[u][0]){
            h[v] = h[u] + 1;
            par[v][0] = u;
            mpar[v][0] = w;

            up(i, 1, 17){
                par[v][i] = par[par[v][i-1]][i-1];
                mpar[v][i] = min(mpar[v][i-1], mpar[par[v][i-1]][i-1]); 
                // 'mpar' and 'par', sometimes confused...
            }
            DFS(v);
        }
    }
}

int MinLCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);

    int fin = 10000007;
    int delta = h[u] - h[v];
    down(i, (int)log2(delta), 0){
        if (bit(delta, i)){
            fin = min(fin, mpar[u][i]);
            u = par[u][i];
        }
    }

    if (u == v) return fin;

    down(i, 17, 0){
        if (par[u][i] != par[v][i]){
            fin = min(fin, min(mpar[u][i], mpar[v][i]));
            u = par[u][i];
            v = par[v][i];
        }
    }
    fin = min(fin, min(mpar[u][0], mpar[v][0]));
    return fin;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    up(i, 1, n){
        fill(mpar[i], mpar[i]+17, 10000007);
    }
    in();
    mark_MST();
    DFS(1);

    long long res = 0;
    up(i, 1, m){
        if (!dd[i]){
            int u = E[i].u;
            int v = E[i].v;
            int w = E[i].w;
            res += max(1ll*0, 1ll*MinLCA(u, v) - 1ll*w);
        }
    }
    cout << res;
    return 0;
}
