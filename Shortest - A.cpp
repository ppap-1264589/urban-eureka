#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task            "A"
#define up(i,a,b)       for (int i = (a); i <= (b); i++)
#define pii             pair<int, int>
#define f               first
#define s               second
#define pb              push_back
#define ep              emplace_back
using namespace std;

const int maxn = 100001;
int n,m;
vector<pii> a[maxn];
int tr[maxn];
int d[maxn];
int s, f;
priority_queue<pii> P;

void in(){
    cin >> n >> m >> s >> f;
    int u,v,w;
    up(i, 1, m){
        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
}

void Dijkstra(){
    fill(d+1, d+n+1, INT_MAX);
    d[s] = 0;

    P.push({-d[s], s});

    while (!P.empty()){
        int u = P.top().s;
        int curw = -P.top().f;
        P.pop();
        if (curw > d[u]) continue;
        for (pii x : a[u]){
            int v = x.f;
            int w = x.s;
            if (d[v] > curw + w){
                d[v] = curw + w;
                tr[v] = u;
                P.push({-d[v], v});
            }
        }
    }
}

void out(){
    vector<int> path;
    cout << "\n";
    while (s != f){
        path.ep(f);
        f = tr[f];
    }
    path.ep(s);
    reverse(path.begin(), path.end());
    for (auto x : path) cout << x << " ";
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    in();
    Dijkstra();
    cout << d[f];
    //out();

    return 0;
}
