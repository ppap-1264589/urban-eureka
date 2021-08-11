#include <bits/stdc++.h>

#define Task                    "F"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define pb                      push_back
#define ep                      emplace_back
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
vector<int> a[maxn];
vector<int> b[maxn];
int n,m;
int low[maxn];
int idx[maxn];
int tdfs;
int SCC;
int inSCC[maxn];
vector<int> x;
set<int> s;

int st[maxn];
int top;
void Tarjan(int u){
    low[u] = idx[u] = ++tdfs;
    st[++top] = u;
    for (int v : a[u]){
        if (inSCC[v]) continue;
        if (!idx[v]){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], idx[v]);
    }

    if (low[u] == idx[u]){
        SCC++;
        while (true){
            int v = st[top--];
            inSCC[v] = SCC;
            if (u == v) break;
        }
    }
}

int dp[maxn];
int DFS(int u){
    if (dp[u] != -1) return dp[u];
    dp[u] = 1;
    for (int v : b[u]){
        dp[u] = max(dp[u], DFS(v) + 1);
    }
    return dp[u];
}

void prepare(){
    cin >> n >> m;
    up(i, 1, n){
        a[i].clear();
        b[i].clear();
    }
    fill(idx, idx+n+1, 0);
    fill(inSCC, inSCC+n+1, 0);
    fill(dp, dp+n+1, -1);
    x.clear();
    s.clear();
    SCC = 0;
    tdfs = 0;
    top = 0;

    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
        s.insert(u);
        s.insert(v);
    }
}

void compress_to_DAG(){
    for (int u : x){
        for (int v : a[u]){
            int ui = inSCC[u];
            int vi = inSCC[v];
            if (ui != vi){
                b[ui].ep(vi);
            }
        }
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--){
        prepare();
        x.assign(s.begin(), s.end());
        // tim tap hop chi chua nhung node co size() != 0

        for (int u : x){
            if (!idx[u]) Tarjan(u);
        }
        compress_to_DAG();

        int res = -1;
        up(i, 1, SCC){
            dp[i] = DFS(i);
            res = max(res, dp[i]);
        }
        cout << ((res == SCC) ? "YES" : "NO"); // neu duong di bang so node cua DAG => YES
        cout << "\n";
    }
    return 0;
}
