//#include <bits/stdc++.h>
//#define pii pair<int, int>
//#define f first
//#define s second
//#define up(i, a, b) for (int i = (a); i <= (b); i++)
//using namespace std;
//
//const int maxn = 100001;
//vector<pair<int, int>> a[maxn];
//
//int n,m;
//int f[maxn];
//
//void in(){
//    cin >> n >> m;
//    int u,v,w;
//    up(i, 1, m){
//        cin >> u >> v >> w;
//        a[u].push_back({v, w});
//    }
//}
//
//int DFS(int u){
//    if (f[u] != -1) return f[u];
//    f[u] = 0;
//    for (pii x : a[u]){
//        int v = x.f;
//        int w = x.s;
//        f[u] = max(f[u], DFS(v) + w);
//    }
//    return f[u];
//}
//
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    freopen ("A.inp", "r", stdin);
//    freopen ("A.out", "w", stdout);
//
//    in();
//    memset(f, -1, sizeof(f));
//    up(i, 1, n){
//        f[i] = DFS(i);
//    }
//    cout << *max_element(f+1, f+n+1);
//
//    ///debug
//    cout << "\n";
//    up(i, 1, n) cout << f[i] << " ";
//    cout << "\n";
//}


#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "A"
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define pii                     pair<int, int>
#define f                       first
#define s                       second
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
vector<pii> a[maxn];
int n,m;
queue<int> q;
int degin[maxn];
int f[maxn];

void in(){
    cin >> n >> m;
    int u,v,w;
    up(i, 1, m){
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        degin[v]++;
    }
}

void DP(){
    for (int i = 1; i <= n; i++){
        if (degin[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int u = q.front();
        for (pii x : a[u]){
            int v = x.f;
            int w = x.s;
            if (f[v] < f[u] + w){
                f[v] = f[u] + w;
            }
            if (--degin[v] == 0) q.push(v);
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
    cout << *max_element(f+1, f+n+1);
    return 0;
}

