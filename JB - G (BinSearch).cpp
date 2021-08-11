#include <bits/stdc++.h>

#define Task                    "G"
#define ll                      long long
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
using namespace std;

const int maxn = 100001;
vector<int> a[maxn];
vector<int> under[maxn];
int Tin[maxn], Tout[maxn], low[maxn], idx[maxn], par[maxn];
bool isJoint[maxn];
int tdfs, step;

void DFS(int u){
    low[u] = idx[u] = ++tdfs;
    Tin[u] = ++step;
    int child = bool(u != 1);
    for (int v : a[u]){
        if (par[u] == v) continue;
        if (!idx[v]){
            par[v] = u;
            DFS(v);

            low[u] = min(low[u], low[v]);
            under[u].emplace_back(v);
            if (low[v] >= idx[u]) child++;
        }
        else low[u] = min(low[u], idx[v]);
    }
    isJoint[u] = bool(child >= 2);
    Tout[u] = ++step;
}
//make the DFS tree
//Tin[i] is the time begin exploring i'th node
//Tout[i] is the time terminate exploring i'th node

bool inDfs(int u, int v){
    return (Tin[u] <= Tin[v] && Tout[v] <= Tout[u]);
}
// check if v is 'under' u (is child of u in DFS tree)

bool toBridge(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    if (Tin[C] > Tin[D]) swap(C, D);
    if (low[D] < idx[D]) return 1;          // not a bridge ?
    return (inDfs(D, A) == inDfs(D, B));
}

bool comp(int x, int y){
    return (Tin[x] < Tin[y]);
}

int get_parent(int u, int v){
    if (!inDfs(u, v)) return -1;            // if v belong to parent node of u (not 'under' u) ?
    int x = *(upper_bound(under[u].begin(), under[u].end(), v, comp) - 1); // combine comp() with upper_bound is more effecient than sort-and-find
    if (low[x] < idx[u]) return -1;         // if x still can comeback to parent of u ?
    return x;
}

bool toJoint(){
    int A, B, C;
    cin >> A >> B >> C;
    if (!isJoint[C]) return 1;
    return (get_parent(C, A) == get_parent(C, B));
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    int n,m;

    cin >> n >> m;
    up(i, 1, m){
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }

    DFS(1);

    int tt;
    cin >> tt;

    int query;
    bool flag;
    while (tt--){
        cin >> query;
        if (query == 1) flag = toBridge();
        else flag = toJoint();
        cout << (flag ? "yes" : "no") << "\n";
    }
    return 0;
}
