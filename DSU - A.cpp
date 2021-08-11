#include <bits/stdc++.h>

#define Task                    "A"
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

const int maxn = 1000001;
int n,u,v,q;
int par[maxn];

int root(int i){
    if (par[i] == 0) return i;
    int x = root(par[i]);
    par[i] = x;
    return x;
}

void Union(int u, int v){
    u = root(u);
    v = root(v);
    if (u != v) par[u] = v;
}

bool Find(int u, int v){
    return (root(u) == root(v));
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    while (q--){
        int c;
        cin >> c >> u >> v;
        if (c == 1) Union(u, v);
        else cout << Find(u, v) << "\n";
    }
    return 0;
}
