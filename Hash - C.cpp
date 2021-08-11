///I tried to code my idea again for 5 times but still can't pass my pretests :(
///Thanks to Nguyen Duc Thien helped me to finish this task and understand more coding skills
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "C"
#define ll                      long long
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define base                    311
//3956221
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 1000001;
const long long MM = 1ll*MOD*MOD;
int n;
ll a[maxn];
ll b[maxn];
ll hashx[maxn];
ll hashn[maxn];
ll D[maxn]; // Decryptor
long long hashB;

void create(){
    up(i, 1, n){
        hashx[i] = (hashx[i-1]*base + a[i]) % MOD;
    }
    down(i, n, 1){
        hashn[i] = (hashn[i+1]*base + a[i]) % MOD;
    }
}

ll getx(int u, int v){
    return (hashx[v] - hashx[u-1]*D[v-u+1] + MM) % MOD;
}

ll getn(int u, int v){
    return (hashn[u] - hashn[v+1]*D[v-u+1] + MM) % MOD;
}

bool check(int k){
    long long sum = 0;
    if ((n - k + 1) % 2 == 0){
        sum = (hashx[k-1] + getx(k, n)*D[k-1]) % MOD;
    }
    else {
        sum = (getn(1, k-1) + getx(k, n)*D[k-1]) % MOD;
    }
    /// Decryptor is generated from 1 to n, so it
    /// only has effect on (1 -> n) hashed substring
    return (sum == hashB);
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    up(i, 1, n) cin >> b[i];
    D[0] = 1;
    up(i, 1, n) D[i] = (D[i-1]*base) % MOD;
    up(i, 1, n){
        hashB = (hashB*base + b[i]) % MOD;
    }
    create();

    vector<int> res;
    for (int i = 1; i <= n; i++){
        if (check(i)) res.push_back(i);
    }

    cout << res.size() << "\n";
    for (auto x : res){
        cout << x << " ";
    }
    return 0;

}
