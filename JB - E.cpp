#include <bits/stdc++.h>

#define Task                    "E"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define base                    311
#define pii                     pair<int, int>
#define f                       first
#define s                       second
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 3*100001;
int n,m;
vector<int> a[maxn];
int Cmax, C;

int low[maxn];
int idx[maxn];
int par[maxn];
int tdfs;

int root;

void DFS(int u){
    int child = (u != root);
    low[u] = idx[u] = ++tdfs;
    for (int v : a[u]){
        if (v == par[u]) continue;
        if (!idx[v]){
            par[v] = u;
            DFS(v);

            low[u] = min(low[u], low[v]);
            if (low[v] >= idx[u]) child++;
        }
        else low[u] = min(low[u], idx[v]);
    }
    if (child > 1){
        if (Cmax < child || (Cmax == child && C > u)){
            Cmax = child, C = u;
        }
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Cmax = INT_MIN;
    C = INT_MAX;
    cin >> n >> m;
    up(i, 1, m){
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }

    int tplt = 0;
    up(i, 1, n){
        if (!idx[i]){
            root = i;
            DFS(i);
            tplt++;
        }
    }

    if (Cmax == INT_MIN){
        cout << tplt << " " << 1;
    }
    else cout << Cmax + tplt - 1 << " " << C; // so thanh phan toi da tao thanh
    return 0;
}
