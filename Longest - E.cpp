#include <bits/stdc++.h>
#define Task "A"
#define pii pair<int, int>
#define f first
#define s second
#define up(i, a, b) for (int i = (a); i <= (b); i++)
#define pb push_back

using namespace std;
const int maxn = 100001;
vector<pii> a[maxn];
int n;
int P[maxn];
long long T[maxn]; // tu con len cha
long long C[maxn]; // tu cha xuong con
int SigmaRice;
const long long MOD = 40000000000000001;

void in(){
    cin >> n;
    int u,v,w;
    up(i, 1, n-1){
        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
    up(i, 1, n){
        cin >> P[i];
        SigmaRice += P[i];
    }
}

int S[maxn];
void DFS1(int u, int par){
    S[u] = P[u];
    for (pii x : a[u]){
        int v = x.f;
        int w = x.s;
        if (v == par) continue;

        DFS1(v, u);
        S[u] += S[v];
        T[u] += T[v] + S[v]*1ll*w;
    }
}

void DFS2(int u, int par){
    for (pii x : a[u]){
        int v = x.f;
        int w = x.s;
        if (v == par) continue;

        C[v] = C[u] + T[u] - T[v] - 1ll*S[v]*w + (1ll*SigmaRice - S[v]) * 1ll*w;
        DFS2(v, u);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    in();
    DFS1(1, -1);
    DFS2(1, -1);

    long long minn = MOD;
    long long maxx = -MOD;
    up(i, 1, n){
//        cout << T[i] << " " << C[i] << "\n";
        T[i] += C[i];
        minn = min(minn, T[i]);
        maxx = max(maxx, T[i]);
    }
    cout << minn << " " << maxx;
    return 0;
}
