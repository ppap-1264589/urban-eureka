#include <bits/stdc++.h>

#define Task            "B"                                 ///map of knowledge
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
int res[maxn];
int Pi[maxn];
int n;
string s;

void KMP(){
    int k = Pi[1] = 0;
    up(i, 2, n){
        while (k && s[k+1] != s[i]) k = Pi[k];
        if (s[k+1] == s[i]) k++;
        Pi[i] = k;
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

    cin >> s;
    n = s.length();
    s = '@' + s;
    KMP();
    fill(res+1, res+n+1, 1);
    down(i, n, 1) res[Pi[i]] += res[i];
    up(i, 1, n) cout << res[i] << " ";
    return 0;
}
