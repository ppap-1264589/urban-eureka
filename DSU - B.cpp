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

const int maxn = 100001;
pii t[maxn];
int res[maxn];
int par[maxn];
int sizee[maxn];

vector<int> a[maxn];
bool d[maxn];
int n,m;

int root(int i){
    if (par[i] == 0) return i;
    int x = root(par[i]);
    par[i] = x;
    return x;
}

void joinn(int u, int v){
    u = root(u);
    v = root(v);
    if (u == v) return;
    par[u] = v;
    sizee[v] += sizee[u];
}

bool cmp(pii x, pii y){
    return (x.f > y.f);
}

signed main(){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    up(i, 1, n){
        cin >> t[i].f;
        t[i].s = i;
        res[i] = -1;
        sizee[i] = 1;
    }

    up(i, 1, m){
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }

    sort(t+1, t+n+1, cmp);
    up(i, 1, n){
        int u = t[i].s;
        d[u] = true;
        for (auto v : a[u]){
            if (d[v]) joinn(u, v);
        }
        int pos = sizee[root(u)];
        if (res[pos] == -1) res[pos] = t[i].f;
    }

    up(i, 1, n) cout << res[i] << " ";
    cout << "\n";

    for (int i = n-1; i >= 1; i--){
        res[i] = max(res[i], res[i+1]);
    }
    up(i, 1, n) cout << res[i] << " ";
    return 0;
}
