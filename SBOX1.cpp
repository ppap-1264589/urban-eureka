#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "SBOX1"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     14062008
#define ll                      long long
#define trail0(x)               (x & (-x))

using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
int n,m;
int u,v;
int BIT[maxn];

void update(int x, int val){
    while (x <= n){
        BIT[x] += val;
        x += trail0(x);
    }
}

int Sum(int x){
    int res = 0;
    while (x > 0){
        res += BIT[x];
        x -= trail0(x);
    }
    return res;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while(m--){
        int c;
        cin >> c >> u >> v;
        if (c == 1){
            update(u, v);
        }
        else cout << Sum(v) - Sum(u-1) << "\n";
    }

    return 0;
}
