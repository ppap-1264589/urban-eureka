#include <bits/stdc++.h>

#define Task                    "C"
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define pii                     pair<int, int>
#define f                       first
#define s                       second
using namespace std;

const int maxn = 100005;
int n,m,res;
int par[maxn*3];
pii a[maxn];
vector<int> v;

int get(int u){
    if (par[u] == 0) return u;
    int x = get(par[u]);
    par[u] = x;
    return x;
}

void calc(int l, int r){
    bool ok = 1;
    int cur = l;
    int des = get(r+1);
    while (cur <= r){ // ?? r+1, do ta chon r+1 lam dai dien cho toan bo cum sector
        int u = get(cur);
        if (u != cur) ok = 0;
        par[cur] = des;
        cur = u+1;
    }
    res += ok;
}

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    up(i, 1, m){
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
        v.emplace_back(l);
        v.emplace_back(r);
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    n = v.size();
    down(i, m, 1){
        a[i].f = lower_bound(v.begin(), v.end(), a[i].f) - v.begin() + 1;
        a[i].s = lower_bound(v.begin(), v.end(), a[i].s) - v.begin() + 1;
        cout << a[i].f << " " << a[i].s << "\n";
        calc(a[i].f, a[i].s);
        up(i, 1, n){
            cout << par[i] << " ";
        }
        cout << "\n";
    }
    cout << res;
    return 0;
}
// omg a really hard time for debuging
