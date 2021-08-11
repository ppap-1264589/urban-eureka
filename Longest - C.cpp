#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
#define up(i, a, b) for (int i = (a); i <= (b); i++)
#define pb push_back
using namespace std;

const int oo = 2*1000000001;
const int maxn = 100001;
vector<pii> a[maxn];
int n,m,L;

void in(){
    cin >> n >> m >> L;
    int u,v,w;
    up(i, 1, m){
        cin >> u >> v >> w;
        u++;
        v++;
        a[u].pb(make_pair(v, w));
        a[v].pb(make_pair(u, w));
    }
}

bool dd[maxn];
int maxx = -1;
vector<int> luu;
int P = 0;
void DFS(int u, int parent, int d[]){
    if (!dd[u]) luu.emplace_back(u);
    dd[u] = 1;
    for (pii x : a[u]){
        int v = x.f;
        int w = x.s;
        if (v == parent) continue;

        d[v] = d[u] + w;
        DFS(v, u, d);
    }
    if (d[P] < d[u]) P = u;
    maxx = max(maxx, d[u]);
}

int cost[maxn];
int dx[maxn];
int dy[maxn];
vector<int> R;
void find_center(int root){
    P = 0;
    DFS(root, -1, cost);
    int X = P;

    P = 0;
    DFS(X, -1, dx);
    int Y = P;

    DFS(Y, -1, dy);

    int minn = oo;
    for (int i : luu){
        minn = min(minn, max(dx[i], dy[i]));
        cost[i] = dx[i] = dy[i] = 0;
    }

    luu.clear();
    R.push_back(minn);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    in();
    if (m == n-1){
        P = 0;
        DFS(1, -1, cost);
        int X = P;
        P = 0;
        fill(cost, cost+n+1, 0);
        DFS(X, -1, cost);
        cout << cost[P];
        return 0;
    }

    up(root, 1, n){
        if (!dd[root]){
            find_center(root);
        }
    }

    int tplt = R.size();
    sort(R.begin(), R.end(), greater<int>());

    if (tplt > 1) maxx = max(maxx, R[0] + R[1] + L);
    if (tplt > 2) maxx = max(maxx, R[1] + R[2] + L*2);

    cout << maxx;
}