#include <bits/stdc++.h>

#define Task                    "F"
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

const int maxn = 100001;
int n,m;
vector<int> a[maxn];
int par[maxn];
int low[maxn];
int idx[maxn];
int tdfs;

int s[maxn];
int res[maxn];
int root;

void DFS(int u){
    int child = bool(u != 1);
    low[u] = idx[u] = ++tdfs;
    s[u] = 1;
    int sum = 0;
    for (int v : a[u]){
        if (par[u] == v) continue;
        if (!idx[v]){
            par[v] = u;
            DFS(v);

            low[u] = min(low[u], low[v]);
            s[u] += s[v];
            if (low[v] >= idx[u]){
                child++;
                res[u] += s[v] * (n - s[v] - 1);
                sum += s[v]; // chi tinh nhung thanh phan thuoc nhanh cua u tren cay DFS sau khi thao bo khop
            }
        }
        else low[u] = min(low[u], idx[v]);
    }
    if (child > 1){
        res[u] += (sum) * (n - sum - 1);
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

    DFS(1);
    up(i, 1, n){
        cout << res[i] + 2*(n-1) << "\n";
    }
    return 0;
}
