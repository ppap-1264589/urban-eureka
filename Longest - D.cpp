#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task            "A"                                  /// map of knowledge
#define bit(x, i)       ((x >> i) & 1)                       //+ Binary Lifting
#define trail0(x)       (x & (-x))                           //+ Hash Table
#define up(i,a,b)       for (int i = (a); i <= (b); i++)     //+ Retrieval Tree
#define down(i,a,b)     for (int i = (a); i >= (b); i--)     //+ Sparse Table - RMQ
#define MOD             1000000007                           //+ Matrix
#define base            311                                  //+ DSU
#define pii             pair<int, int>                       //+ Joints - Bridges
#define f               first                                //+ SCC
#define s               second                               //+ Z-KMP
#define pb              push_back                            //+ MST
#define ep              emplace_back                         //+ LCA
#define MAX_ARR_SIZE    486010000                            //+ Shortest Path
                                                             //+ Fenwick Tree
                                                             //+ Segment Tree
                                                             //+ DP Mask
using namespace std;

const int maxn = 100001;
vector<pii> a[maxn];
int n, k;
double Vp, Vc;
priority_queue <double> PQ;

void in(){
    cin >> n >> k >> Vp >> Vc;

    int u,v,l;
    up(i, 1, n-1){
        cin >> u >> v >> l;
        a[u].pb({v, l});
        a[v].pb({u, l});
    }
}

int sum[maxn];
void DFS(int u, int par){
    for (pii x : a[u]){
        int v = x.f;
        int l = x.s;
        if (v == par) continue;
        sum[v] = 1;
        DFS(v, u);

        sum[u] += sum[v];
        double cost = double(1.0*sum[v] * 1.0*(n - sum[v]) * 1.0*l * (1.0/Vp - 1.0/Vc));
        //remember to cast int to double
        PQ.push(cost);
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
    sum[1]++;
    DFS(1, -1);

//    up(i, 1, n){
//        cout << sum[i] << " ";
//    }
//    cout << "\n";
    double res = 0.0;
    while (k--){
        res += PQ.top();
        PQ.pop();
    }
    cout << fixed << setprecision(2);
    cout << res;
    return 0;
}
