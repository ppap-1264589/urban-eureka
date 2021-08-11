#include <bits/stdc++.h>

#define Task                    "B"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define pb                      push_back
#define ep                      emplace_back
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
int n,m;
vector<int> a[maxn];
int deg[maxn];

queue<int> q;
int f[maxn];

void in(){
    cin >> n >> m;
    int u,v;
    up(i, 1, m){
        cin >> u >> v;
        a[u].ep(v);
        deg[v]++;
    }
}

void add(int& a, int b){
    a = a + b;
    if (a >= MOD) a -= MOD;
}

void DP(){
    up(i, 1, n){
        if (!deg[i]) q.push(i);
    }

    while (!q.empty()){
        int u = q.front();
        for (int v : a[u]){
            add(f[v], f[u] + 1);
            if (--deg[v] == 0) q.push(v);
        }
        q.pop();
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    in();
    DP();

    int res = 0;
    up(i, 1, n) add(res, f[i]);
    cout << res;

    ///debug
    cout << "\n";
    up(i, 1, n){
        cout << f[i] << " ";
    }
    cout << "\n";
    return 0;
}

