#include <bits/stdc++.h>
#define Task            "A"                                  /// map of knowledge
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
#define MAX_ARR_SIZE    486010000                            //+ Shortest Path
                                                             //+ Fenwick Tree
                                                             //+ Segment Tree
                                                             //+ Bitmasking
                                                             //+ Longest Path
                                                             //+ Center Node
                                                             //+ Binary - Ternary Searching
using namespace std;

const int MAXDATA = 201;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<mt19937::result_type> random_number(1, MAXDATA);

int randome(){
    return random_number(RNG);
}

const int maxn = 100001;
int a[maxn];
int b[maxn];
int n,m;

bool check(int h){
    int j = 1;
    up(i, 1, n){
        if (a[i] < h){
            while (j <= m && a[i] + b[j] < h) j++;
            if (j > m) return false;
            j++;
        }
    }
    return true;
}

int Search(){
    int l = 0;
    int r = 2e8;
    while (r - l > 1){
        int mid = (l+r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n;
    up(i, 1, n) cin >> a[i];
    cin >> m;
    up(i, 1, m) cin >> b[i];
    cout << Search();
    return 0;
}
