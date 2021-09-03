#include <bits/stdc++.h>
#define Task "A"
#define up(i,a,b) for (int i = a; i <= b; i++)
#define bit(x,i) ((x >> i) & 1)
#define ep emplace_back
using namespace std;

const int maxn = 501;
vector<int> a[maxn];
int n,m,s,t;
int c[maxn][maxn], f[maxn][maxn];
queue<int> Q;
int tr[maxn];
const int LIM = 2*1e9+31;

void in(){
    cin >> n >> m >> s >> t;
    up(i,1,n){
        cin >> c[i][i+n];
        a[i].ep(i+n);
        a[i+n].ep(i);
    }
    int u,v;
    up(i,1,m){
        cin >> u >> v;
        a[u].ep(v+n);
        a[v].ep(u+n);

        a[u+n].ep(v);
        a[v+n].ep(u);
        c[u+n][v] = c[v+n][u] = LIM;
    }
}

void EdmondsKarp(int root){
    Q = queue<int>{};
    Q.push(root);
    while (!Q.empty()){
        int u = Q.front();
        for (int v : a[u]){
            if (!tr[v] && f[u][v] < c[u][v]){
                tr[v] = u;
                if (v == t+n) return;
                Q.push(v);
            }
        }
        Q.pop();
    }
}

bool argument_path_found(){
    memset(tr, 0, sizeof(tr));
    tr[s] = -1;
    EdmondsKarp(s);
    return tr[t+n];
}

void IncFlow(){
    int de = LIM;
    int v = t+n;
    while (v != s){
        int u = tr[v];
        de = min(de, c[u][v] - f[u][v]);
        v = u;
    }

    v = t+n;
    while (v != s){
        int u = tr[v];
        f[u][v] += de;
        f[v][u] -= de;
        v = u;
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
    while (argument_path_found()) IncFlow();

    vector<int> luu;
    up(i,1,n) if (tr[i] && !tr[i+n]) luu.ep(i);

    cout << luu.size() << "\n";
    for (auto x : luu) cout << x << " ";
}
