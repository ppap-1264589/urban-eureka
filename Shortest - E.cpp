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
#define MAX_ARR_SIZE    486010000                            //+Shortest Path
using namespace std;

const int maxn = 10001;
vector<pii> a[maxn];
int n,m;
int k;
priority_queue<pii, vector<pii>, greater<pii>> P;
vector<vector<int>> d;

void in(){
    int u,v,w;
    cin >> n >> m;
    cin >> k;
    up(i, 1, m){
        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
    d.resize(n+1, vector<int>());
}

void Dijkstra(){
    P.push({0, 1});
    while (!P.empty()){
        int u = P.top().s;
        int curw = P.top().f;
        P.pop();
        if ((d[u].size() != 0 && d[u].back() == curw) || d[u].size() >= k) continue;
        d[u].ep(curw);

        for (pii x : a[u]){
            int v = x.f;
            int w = x.s;
            int val = curw + w;

            if (d[v].size() != 0 && d[v].back() == val || d[v].size() >= k) continue;
            P.push({val, v});
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
    Dijkstra();
    if (d[n].size() == 0) return cout << -1, 0;
    for (int x : d[n]) cout << x << " ";
    return 0;
}
