#include <bits/stdc++.h>

#define Task            "BIT2D"                                  ///map of knowledge
#define bit(x, i)       ((x >> i) & 1)                       //+ Binary Lifting
#define trail0(x)       (x & (-x))                           //+ Hash Table
#define up(i,a,b)       for (int i = (a); i <= (b); i++)     //+ Trie Tree
#define down(i,a,b)     for (int i = (a); i >= (b); i--)     //+ Sparse Table - RMQ
#define MOD             1000000007                           //+ Matrix
#define base            311                                  //+ DSU
#define pii             pair<int, int>                       //+ Joints - Bridges
#define f               first                                //+ SCC
#define s               second                               //+ Z-KMP
#define pb              push_back                            //+ MST
#define ep              emplace_back                         //+ LCA
#define MAX_ARR_SIZE    486010000                            //+Shortest Path
using namespace std;

const int maxn = 1001;
int n,m;
int u,v,p,q;
int BIT[maxn][maxn];

void update(int x, int y, int val){
    while (x <= n){
        for (int v = y; v <= m; v += trail0(v)){
            BIT[x][v] += val;
        }
        x += trail0(x);
    }
}

int get(int x, int y){
    int res = 0;
    while (x > 0){
        for (int v = y; v > 0; v -= trail0(v)){
            res += BIT[x][v];
        }
        x -= trail0(x);
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }
    cin >> n >> m;
    int tt,val;
    cin >> tt;
    while (tt--){
        char c;
        cin >> c;
        cin >> u >> v;
        if (c == 'U'){
            cin >> val;
            update(u, v, val);
        }
        else {
            cin >> p >> q;
            cout << get(p, q) - get(p, v-1) - get(u-1, q) + get(u-1, v-1);
            cout << "\n";
        }
    }
    return 0;
}