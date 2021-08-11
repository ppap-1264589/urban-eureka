#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
#define up(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

const int maxn = 100001;
vector<pair<int, int>> a[maxn];

int n,m;
int f[maxn];

void in(){
    cin >> n >> m;
    int u,v,w;
    up(i, 1, m){
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }
}

int DFS(int u){
    if (f[u] != -1) return f[u];
    f[u] = 0;
    for (pii x : a[u]){
        int v = x.f;
        int w = x.s;
        f[u] = max(f[u], DFS(v) + w);
    }
    return f[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("A.inp", "r", stdin);
    freopen ("A.out", "w", stdout);

    in();
    memset(f, -1, sizeof(f));
    up(i, 1, n){
        f[i] = DFS(i);
    }
    cout << *max_element(f+1, f+n+1);

    ///debug
    cout << "\n";
    up(i, 1, n) cout << f[i] << " ";
    cout << "\n";

}
