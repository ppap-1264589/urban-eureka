#include <bits/stdc++.h>

#define Task                    "E"
#define ll                      long long
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define pb                      push_back
#define ep                      emplace_back
#define bit(x,i)                ((x >> i) & 1)
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 500001;
int n,m;
vector<int> a[maxn];
vector<int> b[maxn];
bool Tg[maxn];

int low[maxn];
int idx[maxn];
int tdfs;

int val[maxn];
int start, p;
bool isgame[maxn];
int cost[maxn];

int SCC;
int inSCC[maxn];
int st[maxn];
int dp[maxn];

int res;

void in(){
    cin >> n >> m;
    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
    }

    up(i, 1, n){
        cin >> val[i];
    }

    cin >> start >> p;
    int pos;
    up(i, 1, p){
        cin >> pos;
        isgame[pos] = 1;
    }
}

int top = 0;
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
        int tol = 0;
        while (true){
            int v = st[top--];
            inSCC[v] = SCC;
            if (isgame[v]) Tg[SCC] = 1;
            tol += val[v];
            if (u == v) break;
        }
        cost[SCC] = tol;
    }
}

int DFS(int u){
    if (dp[u] != -1) return dp[u];
    if (Tg[u]) dp[u] = cost[u];
    else dp[u] = -1000001;
    for (int v : b[u]){
        dp[u] = max(dp[u], DFS(v) + cost[u]);
    }
    return dp[u];
}

signed main (){
//    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    in();
    up(i, 1, n){
        if (!idx[i]) Tarjan(i);
    }

    up(u, 1, n){
        for (int v : a[u]){
            int ui = inSCC[u];
            int vi = inSCC[v];
            if (ui != vi){
                b[ui].ep(vi);
            }
        }
    }

    fill(dp, dp+n+1, -1);
    start = inSCC[start];
    cout << DFS(start);

    return 0;
}
