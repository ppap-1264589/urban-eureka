#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "F"
#define ll                      long long
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define pb                      push_back
#define ep                      emplace_back
#define pii pair<int, int>
#define f first
#define s second
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
int deg[maxn];
int tdfs;
int SCC;
int inSCC[maxn];
stack<int> st;
bool xh[maxn];

void Tarjan(int u){
    low[u] = idx[u] = ++tdfs;
    st.push(u);
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
            int v = st.top();
            st.pop();
            inSCC[v] = SCC;
            if (u == v) break;
        }
    }
}

void Prepare(){
    cin >> n >> m;
    up(i, 1, n){
        a[i].clear();
        b[i].clear();
    }
    fill(idx, idx+n+1, 0);
    fill(inSCC, inSCC+n+1, 0);
    fill(xh, xh+n+1, 0); // đánh dấu đỉnh có tự do hay không
    SCC = 0;
    tdfs = 0;

    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
        xh[u] = xh[v] = true;
    }
}

queue<int> q;
vector<pii> topo;
signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--){
        Prepare();

        up(i, 1, n){
            if (xh[i] && !idx[i]) Tarjan(i);
        }

        up(u, 1, n){
            for (int v : a[u]){
                if (xh[u] && xh[v]){
                    int ui = inSCC[u];
                    int vi = inSCC[v];
                    if (ui != vi){
                        b[ui].ep(vi);
                    }
                }
            }
        } // nén thành DAG

        fill(deg, deg+n+1, 0);
        up(i, 1, SCC){
            for (int v : b[i]){
                deg[v]++;
            }
        }

        up(i, 1, SCC){
            if (!deg[i]) q.push(i);
        }
        topo.clear();
        while (!q.empty()){
            int u = q.front();
            for (int v : b[u]){
                if (--deg[v] == 0){
                    q.push(v);
                    topo.push_back({u, v});
                }
            }
            q.pop();
        }

        bool flag = true;
        for (pii x : topo) {
            if (x.f != x.s + 1){
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}

/// Đánh số lại đồ thị bằng Tarjan
/// sắp xếp các cạnh theo topo
/// để đi hết trên DAG thì phải "1 đi không trở lại"
/// nên các cạnh sau khi sắp xếp topo phải thoã mãn các đỉnh liền kề nhau
/// 1-2, 2-3, 3-4
/// n-1, n
