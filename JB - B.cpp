#include <bits/stdc++.h>

#define Task                    "B"
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

const int maxn = 100002;
int n,m,par[maxn];
vector<int> a[maxn];
vector<int> res;
int num[maxn], low[maxn]; // low = lowest
int tdfs;

void DFS(int u){
    int child = bool(par[u] != -1); // bool == 0 khi u la goc DFS
    low[u] = num[u] = ++tdfs;
    for (int v : a[u]){
        if (v == par[u]) continue;
        if (!num[v]){
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) child++;
        }
        else low[u] = min(low[u], num[v]);
    }
    if (child > 1) res.emplace_back(u);
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

    up(i, 1, n){
        if (!par[i]){
            par[i] = -1;
            DFS(i);
        }
    }

    cout << res.size() << "\n";
    sort(res.begin(), res.end());
    for (auto x : res) cout << x << " ";
    return 0;
}
