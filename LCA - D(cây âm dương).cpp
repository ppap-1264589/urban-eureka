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
int par[maxn][18];
int sum[maxn];
int h[maxn];
int res = -1;

void in1(){
    cin >> n;
    int u,v;
    up(i, 1, n-1){
        cin >> u >> v;
        a[u].ep(v);
        a[v].ep(u);
    }
}

int LCA(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int de = h[u] - h[v];
    down(i, (int)log2(de), 0){
        if (bit(de, i)) u = par[u][i];
    }

    if (u == v) return v;

    down(i, 17, 0){
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

void in2(){
    cin >> m;
    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        int p = LCA(u, v);
        sum[u]--;
        sum[v]--;
        sum[p] += 2;
    }
}

void DFS(int u){
    for (int v : a[u]){
        if (v != par[u][0]){
            par[v][0] = u;
            h[v] = h[u] + 1;

            up(i, 1, 17){
                par[v][i] = par[par[v][i-1]][i-1];
            }
            DFS(v);
        }
    }
}

void reDFS(int u){
    for (int v : a[u]){
        if (v != par[u][0]){
            reDFS(v);
            sum[u] += sum[v];
        }
    }
    if (sum[u] == 0) res++;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    in1();
    DFS(1);
    in2();
    reDFS(1);
    cout << res;

    return 0;
}
