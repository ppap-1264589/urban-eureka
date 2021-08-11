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

const int maxn = 3*100000+1;
int n;
int a[maxn], z[maxn];

void TinhZ(){
    z[1] = 0;
    int l = 0;
    int r = 0;
    up(i, 2, n){
        int x = 0;
        if (i <= r) x = min(z[i-l+1], r-i+1);
        while (i + x <= n && a[x+1] == a[i+x]) x++;

        z[i] = x;
        if (i + x - 1 > r){
            l = i;
            r = i + x - 1;
        }
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

    cin >> n;
    up(i, 1, n) cin >> a[i];
    TinhZ();
//    up(i, 1, n) cout << z[i] << " ";
//    cout << "\n";

    up(i, 1, n){
//        cout << i + 1 + z[i+1] << " " << n-i << "\n";
        if (z[i+1] == n-i) {
            cout << i;
            break;
        }
    }

    return 0;
}
