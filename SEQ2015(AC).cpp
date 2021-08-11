#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task            "SEQ2015"                                  /// map of knowledge
#define bit(x, i)       ((x >> i) & 1)                       //+ Binary Lifting
#define trail0(x)       (x & (-x))                           //+ Hash Table
#define up(i,a,b)       for (int i = (a); i <= (b); i++)     //+ Trie Tree
#define down(i,a,b)     for (int i = (a); i >= (b); i--)     //+ Sparse Table - RMQ
#define MOD             30103                                //+ Matrix
#define base            311                                  //+ DSU
#define pii             pair<int, int>                       //+ Joints - Bridges
#define f               first                                //+ SCC
#define s               second                               //+ Z-KMP
#define pb              push_back                            //+ MST
#define ep              emplace_back                         //+ LCA
#define MAX_ARR_SIZE    486010000                            //+ Shortest Path
                                                             //+ Fenwick Tree
                                                             //+ Segment Tree
using namespace std;


const int maxn = 701;
int n;
int a[maxn];
int dp[maxn][maxn];
int BIT[maxn][2001]; // do abs(a[i]) co the dat toi 1000 -> (a[i] + a[j] <= 2000)

void update(int x, int y, int val){
    while (x <= maxn){
        for (int v = y; v <= 2001; v += trail0(v)){
            BIT[x][v] += val;
        }
        x += trail0(x);
    }
}

int get(int x, int y){
    int cur = 0;
    while (x > 0){
        for (int v = y; v > 0; v -= trail0(v)){
            cur = (cur + BIT[x][v]) % MOD;
        }
        x -= trail0(x);
    }
    return cur;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    scanf("%d", &n);
    up(i, 1, n) scanf("%d", &a[i]);

    down(j, n, 2){
        down(i, j-1, 1){
            int x = a[i] + a[j];
            dp[i][j] = (get(i-1, 2001) - get(i-1, x) + 1 + MOD) % MOD;
            update(i, x, dp[i][j]);
        }
    }

    int res = 0;
    up(i, 1, n){
        up(j, i+1, n){
            res = (res + dp[i][j] - 1 + MOD) % MOD;
        }
    }
    up(i, 1, n){
        up(j, 1, n){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    printf("%d", res);
    return 0;
}
