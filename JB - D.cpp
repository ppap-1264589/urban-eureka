#include <bits/stdc++.h>

#define Task                    "D"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define int long long
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100101;
vector<int> a[maxn];
int n,m;

int par[maxn];
int low[maxn];
int idx[maxn];
int tdfs;

int bridges;
int under[maxn];

int d[maxn];
int res;

void findSCC(int u){ // strong connected components
    for (int v : a[u]){
        if (!d[v]){
            d[v] = -1;
            findSCC(v);
        }
    }
}

void DFS(int u){
    low[u] = idx[u] = ++tdfs;
    under[u] = 1;
    for (int v : a[u]){
        if (v == par[u]) continue;
        if (!idx[v]){
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            under[u] += under[v];
            if (low[v] == idx[v]){
                bridges++;
            }
        }
        else low[u] = min(low[u], idx[v]);
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    up(i, 1, m){
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }

    int tplt = 0;
    up(i, 1, n){
        if (!d[i]){
            d[i] = -1;
            findSCC(i);
            tplt++;
        }
    }

    if (tplt >= 3) cout << "0";

    if (tplt == 2){
        up(i, 1, n){
            if (!idx[i]){
                DFS(i);
                break;
            }
        }
        res = tdfs * (n - tdfs);

        up(i, 1, n){
            if (!idx[i]){
                DFS(i);
            }
        } // co ve DFS them phat nua khong thong minh lam =(

        // tdfs = so dinh thuoc tplt 1
        // n - tdfs = so dinh thuoc tplt 2
        // m - bridges = so canh con lai khac bridges

        cout << res * (m - bridges);
    }

    if (tplt == 1) {
        DFS(1);
        res = (m-bridges)*(1ll*n*(n-1)/2 - m);
        up(i, 2, n){
            if (low[i] == idx[i]){
                res += under[i] * (n - under[i]) - 1;
            }
        }
        cout << res;
    }

    ///debug
    cout << "\n";
    cout << bridges << " ";
    cout << tdfs << " ";

    return 0;
}
