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
int a[maxn][maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n >> m;
    int tt;
    cin >> tt;
    int u,v;
    while (tt--){
        char c;
        cin >> c >> u >> v;
        if (c == 'U') {
            int val;
            cin >> val;
            a[u][v] += val;
        }
        else {
            int x,y;
            cin >> x >> y;
            int res = 0;
            for (int i = u; i <= x; i++){
                for (int j = v; j <= y; j++){
                    res += a[i][j];
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}
