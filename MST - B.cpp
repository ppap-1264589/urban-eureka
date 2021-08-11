#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task            "A"                                 ///map of knowledge
#define ll              long long                           //+ Binary Lifting
#define bit(x,i)        ((x >> i) & 1)                      //+ Hash Table
#define stt(x,i)        (x & (1 << i))                      //+ Retrieval Tree
#define trail0(x)       (x & (-x))                          //+ Sparse Table - RMQ
#define up(i,a,b)       for (int i = (a); i <= (b); i++)    //+ Matrix
#define down(i,a,b)     for (int i = (a); i >= (b); i--)    //+ DSU
#define MOD             1000000007                          //+ Joints - Bridges
#define base            311                                 //+ SCC
#define pii             pair<int, int>                      //+ Z-KMP
#define f               first
#define s               second
using namespace std;

const int maxn = 5001;
pii a[maxn];
bool is0[maxn][maxn];
double Op[maxn];
bool d[maxn];
double ans = 0;
int n,m;

double sqr(int x){
    return x*x;
}

double dist(int i, int j, pii a, pii b){
    if (is0[i][j] || is0[j][i]) return 0;
    return sqrt(sqr(a.f - b.f) + sqr(a.s - b.s));
}

void Push(int u){
    d[u] = 1;
    up(v, 1, n){
        double k = dist(u, v, a[u], a[v]);
        if (!d[v] && Op[v] > k) Op[v] = k;
    }
}

void Prim(int root){
    Op[root] = 0;
    Push(root);
    while (true){
        int u = 0;
        up(i, 1, n) {
            if (!d[i] && Op[u] > Op[i]) u = i;
        }
        if (u == 0) break;
        ans += Op[u];
        Push(u);
    }
}

int x,y;
signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n;
    up(i, 1, n){
//        cin >> x >> y;
//        a[i] = {x, y};
///       Bài học để đời, đừng cin như cách trên :') tràn bộ nhớ như chơi
        cin >> a[i].f >> a[i].s;
    }

    cin >> m;
    up(i, 1, m){
        cin >> x >> y;
        is0[x][y] = is0[y][x] = true;
    }
    up(i, 0, n+1) Op[i] = 1e9 + 7;
    Prim(1);

    cout << fixed << setprecision(2);
    cout << ans << "\n";
//    up(i, 1, n) cout << Op[i] << " ";

    return 0;
}
