#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "A"
#define ll                      long long
#define bit(x,i)                (x & (1 << (i)))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     14062008
#define base                    3956221
#define pii                     pair<int, int>
#define f                       first
#define s                       second
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 1000001;
const long long MM = 1ll*MOD*MOD;

int H[maxn];
int B[maxn];
string a,b;
int n,m;

int gethash(int u, int v){
    return (B[v] - B[u-1]*H[n] + MM) % MOD;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = '@' + a;
    b = '@' + b;

    int hashA = 0;
    for (int i = 1; i <= n; i++){
        hashA = (hashA*base + a[i]) % MOD;
    } // Hash code of string a

    H[0] = 1;
    for (int i = 1; i <= m; i++){
        B[i] = (B[i-1]*base + b[i]) % MOD;
        // Hash code of substrings from 1 to i in b
        H[i] = (H[i-1]*base) % MOD;
        // Decryptor
    }

    vector<int> res;
    for (int v = n; v <= m; v++){
        int u = v - n + 1;
        if (gethash(u, v) == hashA){
            res.push_back(u);
        }
    }
    cout << res.size() << "\n";
    for (auto x : res) cout << x << " ";
    return 0;
}
