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

const int maxn = 10001;
int n,m;
vector<pii> a[maxn];
priority_queue<pii, vector<pii>, greater<pii>> P;
int da[maxn];
int db[maxn];

void in(){
    cin >> n >> m;
    int u,v,w;
    up(i, 1, m){
        cin >> u >> v >> w;
        a[u].pb(make_pair(v, w));
        a[v].pb(make_pair(u, w));
    }
}

void Dijkstra(){
    fill(da, da+n+1, INT_MAX);
    da[1] = 0;
    P.push({0, 1});
    while (!P.empty()){
        int curw = P.top().f;
        int u = P.top().s;
        P.pop();
        if (curw > da[u]) continue;
        for (pii x : a[u]){
            int v = x.f;
            int w = x.s;
            if (da[v] > curw + w){
                da[v] = curw + w;
                P.push({da[v], v});
            }
        }
    }

    fill(db, db+n+1, INT_MAX);
    db[2] = 0;
    P.push({0, 2});
    while (!P.empty()){
        int curw = P.top().f;
        int u = P.top().s;
        P.pop();
        if (curw > db[u]) continue;
        for (pii x : a[u]){
            int v = x.f;
            int w = x.s;
            if (db[v] > curw + w){
                db[v] = curw + w;
                P.push({db[v], v});
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

    in();
    Dijkstra();
    int res = 0;
    up(i, 1, n){
        res += da[i];
    }

    vector<int> T;
    up(i, 1, n){
        T.ep(db[i] - da[i]);
    }
    sort(T.begin(), T.end());
    for (int i = 0; i < n/2; i++) res += T[i];
    cout << res;
    return 0;
}
