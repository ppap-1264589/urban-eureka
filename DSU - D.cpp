#include <bits/stdc++.h>

#define Task                    "D"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define base                    311
#define pii                     pair<int, int>
#define f                       first
#define s                       second
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 3*100001;
int n,m;
int l,r,x;
int par[maxn];
int res[maxn];

void init(){
    up(i, 1, n){
        par[i] = i;
    }
}

int root(int u){
    if (u == par[u]) return u;
    int x = root(par[u]);
    par[u] = x;
    return x;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    up(i, 1, m){
        cin >> l >> r >> x;
        int des = root(r+1);
        while (l <= r){
//            up(i, 1, n) cout << par[i] << " ";
//            cout << "\n";
//            up(i, 1, n) cout << res[i] << " ";
//            cout << "\n" << "\n";
            int u = root(l);
            if (u > r) break;
            if (u < x){
                par[u] = x;
                res[u] = x;
            }
            else if (u > x){
                par[u] = des;
                res[u] = x;
            }
            l = u + 1;
        }

    }
    up(i, 1, n) cout << res[i] << " ";
    return 0;
}
