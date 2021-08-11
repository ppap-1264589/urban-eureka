/// Thanks Nguyen Duc Thien for supporting me to solve this problem
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
#define MAX_ARR_SIZE    486010000                            //+Shortest Path
using namespace std;

const int maxn = 1001;
int n,m,s,f;
priority_queue<pii, vector<pii>, greater<pii>> P;

vector<pii> a[maxn*2];
vector<pii> g[2][maxn];
int d[2][maxn];
int dist[maxn*2];
bool instack[maxn*2];

void Input(int type){
    cin >> m;
    up(i, 1, m){
        int u,v,w;
        cin >> u >> v >> w;
        g[type][u].pb({v, w});
        g[type][v].pb({u, w});
    }
}

void Dijkstra(int type){
    fill(d[type]+1, d[type]+n+1, MOD);
    d[type][f] = 0;
    P.push({0, f}); // do phai chuan hoa cac canh theo
                    // chieu giam dan cua khoang cach khi di tu u -> v
                    // theo tieu chi w(u -> finish) > w(v -> finish)
                    // => Quy hoach tai vi tri f
    while (!P.empty()){
        int u = P.top().s;
        int curw = P.top().f;
        P.pop();
        if (curw > d[type][u]) continue;

        for (pii x : g[type][u]){
            int v = x.f;
            int w = x.s;
            if (d[type][v] > curw + w){
                d[type][v] = curw + w;
                P.push({d[type][v], v});
            }
        }
    }
}

void ChuanHoa(int type){
    up(u, 1, n){
        for (pii x : g[type][u]){
            int v = x.f;
            int w = x.s;
            if (d[type][u] > d[type][v]){ // di tu u den v sao cho w(u -> finish) > w(v -> finish)
                if (type == 0){
                    a[u + n].pb({v, w});
                }
                else a[u].pb({v + n, w});
            }
        }
    }
}

bool dd[maxn*2];
void DFS(int u){
    if (u == f || u == f+n) dist[u] = 0;
    dd[u] = 1;
    instack[u] = 1;
    for (pii x : a[u]){
        int v = x.f;
        int w = x.s;
        if (instack[v]){
            cout << -1;
            exit(0);
        }
        if (!dd[v]) DFS(v);
        dist[u] = max(dist[u], dist[v] + w);
    }
    instack[u] = 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n >> s >> f;
    up(type, 0, 1){
        Input(type);
        Dijkstra(type);
        ChuanHoa(type);
    }
    fill(dist+1, dist+n+n+1, -MOD);
    DFS(s+n);
    // do bat dau tai duong bo nen DFS tu (source+n)

    if (dist[s+n] < 0) cout << -1;
    else cout << dist[s+n];

//    cout << "\n";
//    up(i, 1, n) cout << dist[i] << " ";
    return 0;
}
