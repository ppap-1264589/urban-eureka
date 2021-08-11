#include <bits/stdc++.h>

#define Task            "A"                                 ///map of knowledge
#define ll              long long                           //+ Binary Lifting
#define bit(x,i)        ((x >> i) & 1)                      //+ Hash Table
#define stt(x,i)        (x & (1 << i))                      //+ Trie Tree
#define trail0(x)       (x & (-x))                          //+ Sparse Table - RMQ
#define up(i,a,b)       for (int i = (a); i <= (b); i++)    //+ Matrix
#define down(i,a,b)     for (int i = (a); i >= (b); i--)    //+ DSU
#define MOD             1000000007                          //+ Joints - Bridges
#define base            311                                 //+ SCC
#define pii             pair<int, int>                      //+ Z-KMP
#define f               first
#define s               second
#define pb              push_back
#define ep              emplace_back
using namespace std;

const int maxn = 100001;
int n,m;
vector<int> a[maxn];
vector<int> ra[maxn];
vector<int> ds;
short d[maxn];
vector<int> res[maxn];
int scc;

void DFS1(int u){
    d[u] = 1;
    for (int v : a[u]){
        if (!d[v]) DFS1(v);
    }
    ds.ep(u);
}

void DFS2(int u){
    res[scc].ep(u);
    d[u] = 2;
    for (int v : ra[u]){
        if (d[v] != 2) DFS2(v);
    }
}

bool cmp(const vector<int>& x, const vector<int>& y){
    return (x.size() != y.size() ? x.size() < y.size() : x[0] < y[0]);
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n >> m;
    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
        ra[v].ep(u);
    }

    up(i, 1, n){
        if (!d[i]) DFS1(i);
    }

    reverse(ds.begin(), ds.end());
    for (int u : ds){
        if (d[u] != 2){
            scc++;
            DFS2(u);
        }
    }

    cout << scc << "\n";
    up(i, 1, scc) sort(res[i].begin(), res[i].end());
    sort(res+1, res+scc+1, cmp);
    up(i, 1, scc){
        cout << res[i].size() << "\n";
        for (auto x : res[i]) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

///Kosaraju Implementation
