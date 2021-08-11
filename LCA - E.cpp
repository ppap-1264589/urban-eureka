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
#define MAX_ARR_SIZE    486010000
using namespace std;

const int maxn = 100001;
vector<int> a[maxn];
int tr[maxn];
int dist[maxn];
bool dd[maxn];
queue<int> q;
vector<int> luu;
int par[maxn][18];
int pmin[maxn][18];
int n,m,s,f;

void in(){
    cin >> n >> m >> s >> f;
    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
        a[v].ep(u);
    }
}

void BFS(int root){
    dist[root] = 0;
    dd[root] = 1;
    luu.ep(root);

    q.push(root);
    while (!q.empty()){
        int u = q.front();
        for (int v : a[u]){
            if (!dd[v]){
                q.push(v);
                luu.ep(v);
                dist[v] = dist[u] + 1;
                dd[v] = 1;
                if (v == f) return;
            }
        }
        q.pop();
    }
}

bool isbetter(int u, int v){
    int PminU = n+1;
    int PminV = n+1;
    down(i, 17, 0){
        if (par[u][i] != par[v][i]){
            PminU = min(PminU, pmin[u][i]);
            PminV = min(PminV, pmin[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    PminU = min(PminU, pmin[u][0]);
    PminV = min(PminV, pmin[v][0]);
    return (PminU < PminV);
}

void DP(){
    for (int u : luu){
        for (int v : a[u]){
            if (dist[v] == dist[u] - 1){
                if (tr[u] == 0 || isbetter(v, tr[u])) tr[u] = v;
            }
        }
        pmin[u][0] = u;
        par[u][0] = tr[u];
        up(i, 1, 17){
            int p = par[u][i-1];
            par[u][i] = par[p][i-1];
            pmin[u][i] = min(pmin[u][i-1], pmin[p][i-1]);
        }
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
    BFS(f);
    if (!dd[s]){
        cout << -1;
        return 0;
    }
    DP();
    //up(i, 1, n) cout << tr[i] << "\n";

    while (s != f){
        cout << s << " ";
        s = tr[s];
    }
    cout << s;
    return 0;
}
