#include <bits/stdc++.h>

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
int n,m;
vector<int> a[maxn];
int low[maxn];
int idx[maxn];
int par[maxn];
int tdfs;
map<pii, bool> ma;
vector<pii> res;
int tol;

void in(){
    cin >> n;
    int u,v;
    up(i, 1, n-1){
        cin >> u >> v;
        a[u].ep(v);
        a[v].ep(u);
    }
    cin >> m;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
        a[v].ep(u);
        ma[{min(u, v), max(u, v)}] = 1;
    }
}

void Tarjan(int u){
    low[u] = idx[u] = ++tdfs;
    for (int v : a[u]){
        if (v == par[u]) continue;
        if (!idx[v]){
            par[v] = u;
            Tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == idx[v]){
                res.pb({min(u, v), max(u, v)});
                tol++;
            }
        }
        else low[u] = min(low[u], idx[v]);
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
    up(i, 1, n){
        if (!idx[i]){
            Tarjan(i);
        }
    }
    for (pii x : res){
        if (ma[x]) tol--;
    }

    cout << tol;
    return 0;
}
