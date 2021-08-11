#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
using namespace std;

const int maxn = 201;
int M[maxn][maxn];
struct edge{
    int u, v, w;
};
vector<edge> a;
int par[20001];
int n,k;
int dem;
int cnt;
int res = MOD;

int root(int u){
    if (par[u] == 0) return u;
    int x = root(par[u]);
    par[u] = x;
    return x;
}

bool Union(int u, int v){
    u = root(u);
    v = root(v);
    if (u != v){
        par[u] = v;
        return true;
    }
    return false;
}

bool cmp(const edge& x, const edge& y){
    return (x.w < y.w);
}

void Kruskal(){
    sort(a.begin(), a.end(), cmp);
    for (edge x : a){
        int u = x.u;
        int v = x.v;
        if (dem == k){
            for (edge e : a){
                u = e.u;
                v = e.v;
                if (root(u) != root(v)){
                    res = min(res, e.w);
                }
            }
            cout << res;
            return;
        }
        if (Union(u, v)) dem--;
    }
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n >> k;
    up(i, 1, n){
        up(j, 1, n){
            cin >> M[i][j];
        }
    }

    up(i, 1, n){
        up(j, i+1, n){
            a.push_back({i, j, M[i][j]});
        }
    }


    dem = n;
    cnt = n*(n-1)/2;
    Kruskal();
//    for (edge x : a) cout << x.u << " " << x.v << " " << x.w << "\n";
    return 0;
}
