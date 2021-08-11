#include <bits/stdc++.h>
#define Task                    "F"
#define ll                      long long
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define pii                     pair<int, int>
#define f                       first
#define s                       second
#define reset(X)                memset(X, 0, sizeof(X))
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 1003;  // 10^3 maxn
const int dx[5] = {0,0,0,1,-1};
const int dy[5] = {0,1,-1,0,0};

int n,m,q;
int res[10*maxn];
int par[maxn*maxn];
int color[maxn][maxn];
int cnt = 0;
int dem = 0;
int xx1,xx2,yy1,yy2;
vector<pii> td[10*maxn]; // 10^4 q

int root(int u){
    if (par[u] == 0) return u;
    par[u] = root(par[u]);
    return par[u];
}

void joinn(int u, int v){
    if (u == 0 || v == 0) return;
    u = root(u);
    v = root(v);
    if (u == v) return;
    par[u] = v;
    cnt--;
}

void update(int u, int v){
    color[u][v] = ++dem;
    cnt++;
    up(i, 1, 4){
        int ux = u + dx[i];
        int vx = v + dy[i];
        joinn(dem, color[ux][vx]);
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    up(i, 1, q){
        cin >> xx1 >> yy1 >> xx2 >> yy2;
        up(u, xx1, xx2){
            up(v, yy1, yy2){
                if (color[u][v] == 0){
                    color[u][v] = 1;
                    td[i].push_back({u, v});
                }
            }
        }
    }

    up(u, 1, n){
        up(v, 1, m){
            if (!color[u][v]){
                td[q+1].push_back({u, v});
            }
        }
    }

    reset(color);
    for (int i = q+1; i > 1; i--){
        for (auto x : td[i]){
            update(x.f, x.s);
        }
        res[i-1] = cnt;
    }

    up(i, 1, q) cout << res[i] << "\n";
    return 0;
}
