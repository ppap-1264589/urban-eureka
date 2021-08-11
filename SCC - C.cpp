#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "C"
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define pii                     pair<int, int>
#define f                       first
#define s                       second
#define ep                      emplace_back
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
vector<int> a[maxn];
int n,m;

int low[maxn];
int idx[maxn];
int tdfs;

bool inSCC[maxn];
stack<int> st;
vector<int> res[maxn];
int SCC;

void in(){
    cin >> n >> m;
    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
    }
}

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
            res[SCC].ep(v);
            inSCC[v] = true;
            if (v == u) break;
        }
        sort(res[SCC].begin(), res[SCC].end());
    }
}

bool cmp(const vector<int>& x, const vector<int>& y){
    if (x.size() == y.size()) return (x[0] < y[0]);
    return (x.size() < y.size());
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    in();
    up(i, 1, n){
        if (!idx[i]) Tarjan(i);
    }
    sort(res+1, res+SCC+1, cmp);
    cout << SCC << "\n";
    up(i, 1, SCC){
        cout << res[i].size() << "\n";
        for (auto x : res[i]) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
