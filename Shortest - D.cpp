#include <bits/stdc++.h>

#define Task            "D"                                  ///map of knowledge
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

const int maxn = 10001;
vector<pii> a[maxn];
int d[maxn];
priority_queue<pii> P;
int n;
int u,v,w1,w2;
char T;

void add(int f1, int f2, int w){
    a[f1].pb({f2, w});
}

void Dijkstra(){
    fill(d, d+n+n+1, INT_MAX);
    d[n] = d[n+n] = 0;
    P.push({-d[n], n});
    P.push({-d[n+n], n+n});
    while (!P.empty()){
        int u = P.top().s;
        int curw = -P.top().f;
        P.pop();

        if (u == 1 || u == n+1) break;
        if (curw > d[u]) continue;
        for (pii x : a[u]){
            int v = x.f;
            int w = x.s;
            if (d[v] > curw + w){
                d[v] = curw + w;
                P.push({-d[v], v});
            }
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

    cin >> n;
    while (cin >> u >> v >> w1 >> w2 >> T){
        if (T == 'M'){
            add(u, v+n, w1);
            add(v+n, u, w2);
        }
        else {
            add(u+n, v, w1);
            add(v, u+n, w2);
        }
    }

    Dijkstra();
    int res = min(d[1], d[n+1]);
    if (res == INT_MAX) cout << -1;
    else cout << res;
    return 0;
}
