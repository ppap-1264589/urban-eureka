#include <bits/stdc++.h>

#define Task                    "D"
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
#define pb                      push_back
#define ep                      emplace_back
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
int n,m;
vector<int> a[maxn];
vector<pii> ma;
int intplt[maxn];

int low[maxn];
int idx[maxn];
int tdfs;
int SCC;
deque<int> st;

long long res;

void in(){
    cin >> n >> m;
    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
        ma.pb({u, v});
    }
}

void DFS(int u){
    low[u] = idx[u] = ++tdfs;
    st.push_back(u);
    for (int v : a[u]){
        if (intplt[v]) continue;
        if (!idx[v]){
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], idx[v]);
    }

    if (low[u] == idx[u]){
        SCC++;
        long long k = 0;
        while (1){
            int v = st.back();
            st.pop_back();
            k++;
            intplt[v] = SCC;
            if (u == v) break;
        }
        res += k*(k-1);
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    in();
    up(i, 1, n){
        if (!idx[i]) {
            DFS(i);
            st.clear();
        }
    }

    set<pii> s(ma.begin(), ma.end());
    ma.assign(s.begin(), s.end());

    for (vector<pii>::iterator it = ma.begin(); it != ma.end(); it++){
        int u = it->f;
        int v = it->s;
        if (intplt[u] == intplt[v]){
            res--;
        }
    }
    cout << res;
    return 0;
}
