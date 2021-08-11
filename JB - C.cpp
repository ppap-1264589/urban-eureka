#include <bits/stdc++.h>
#define up(i, a, b) for (int i = (a); i <= (b); i++)
#define down(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen ("C.inp", "r", stdin);
    freopen ("C.out", "w", stdout);
}

const int maxn = 100001;
int n,m,k,l;
int sa[maxn];
int sb[maxn];
vector<int> a[maxn];
int tdfs;
int id[maxn];
int low[maxn];
int par[maxn];
int bridges;

void DFS(int u){
    low[u] = id[u] = ++tdfs;
    for (int v : a[u]){
        if (par[u] == v) continue;
        if (!id[v]){
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            sa[u] += sa[v];
            sb[u] += sb[v];
            if (low[v] == id[v]){
                if (sa[v] == 0 || sa[v] == k ||
                    sb[v] == 0 || sb[v] == l){
                        bridges++;
                    }
            }
        }
        else low[u] = min(low[u], id[v]);
    }
}

int main (){
    setFile();
    cin >> n >> m >> k >> l;
    up(i, 1, k){
        int x;
        cin >> x;
        sa[x] = 1;
    }
    up(i, 1, l){
        int x;
        cin >> x;
        sb[x] = 1;
    }

    up(i, 1, m){
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }

    down(i, n, 1){
        if (!par[i]){
            par[i] = -1;
            DFS(i);
        }
    }

    ///debug
//    up(i, 1, n) cout << sa[i] << " ";
//    cout << "\n";
//    up(i, 1, n) cout << sb[i] << " ";
//    cout << "\n";

    cout << bridges;
}

//omg such a long time for debugging
