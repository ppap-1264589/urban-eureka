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

const int maxn = 2000001;
string s;
int z[maxn];
int p[maxn];
int f[maxn];
int n;

void TinhZ(){
    int l = 0, r = 0;
    up(i, 2, n){
        int x = 0;
        if (i <= r) x = min(z[i-l+1], r-i+1);
        while (i + x <= n && s[x+1] == s[i+x]) x++;

        z[i] = x;
        if (i + x - 1 > r){
            l = i;
            r = i + x - 1;
        }
    }
}

void KMP(){
    int k = p[1] = 0;
    up(i, 2, n){
        while (k && s[k+1] != s[i]) k = p[k];
        if (s[k+1] == s[i]) k++;
        p[i] = k;
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
    TinhZ();
    KMP();

    fill(f+1, f+n+1, 1);
    down(i, n, 1) f[p[i]] += f[i];

//    up(i, 1, n) cout << z[i] << " ";
//    cout << "\n";
//    up(i, 1, n) cout << f[i] << " ";
//    cout << "\n";

    down(i, n, 1){
        if (f[i] >= 3 && z[n-i+1] == i){
            cout << s.substr(1, i);
            return 0;
        }
    }
    cout << "No solution!";
    return 0;
}
