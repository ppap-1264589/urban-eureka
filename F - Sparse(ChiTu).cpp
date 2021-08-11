#include <bits/stdc++.h>
#define TASK "A"
#define int long long
#define maxn 128
#define maxx 2000000000000000000ll

//As a game
//I'll get victory!
//As an experience
//I'll enjoy it.
//As a battle
//I'll be a Strong Warrior.


using namespace std;
// ATTEMPED 8.
int n, m, k, Count, t;
int answer = maxx;
int f[maxn][maxn][40], h[40], logarit[40];
int result[maxn][maxn], a[maxn][maxn];
int abc(int Stacia, int Kirito){
    int Asuna = logarit[Kirito];
    if(Kirito == Count) return f[Stacia][t][Asuna + 1];
    int Collaboration = maxx;
    for(int i = 1; i <= n; i++)
        if(f[Stacia][i][Asuna + 1] != maxx){
            int Alicization = result[i][Kirito+1];
            Collaboration = min(Collaboration, f[Stacia][i][Asuna + 1] + Alicization);
        }
    return Collaboration;
}

void Initialization(){
    h[0] = 1;
    for(int i = 1; i <= 30; i++) h[i] = h[i-1]*2;
    while(k > 0){
        Count++;
        logarit[Count] = log2(k);
        k -= 1 << logarit[Count];
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
            if(a[i][j] == 0) f[i][j][1] = maxx;
    for(int Stacia = 2; Stacia <= 30; Stacia++) for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(f[i][j][Stacia] == 0) f[i][j][Stacia] = maxx;
            for(int Kirito = 1; Kirito <= n; Kirito++)
                f[i][j][Stacia] = min(f[i][j][Stacia], f[i][Kirito][Stacia-1] + f[Kirito][j][Stacia - 1]);
        }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(a[u][v] != 0)
            a[u][v] = min(a[u][v], w);
        else a[u][v] = w;
        f[u][v][1] = a[u][v];
    }
    Initialization();
    for(int i = 1; i <= n; i++){
        t = i;
        for(int k = Count; k >= 1; k--) for(int j = 1; j <= n; j++) result[j][k] = abc(j, k);
        answer = min(answer, result[i][1]);
    }
    if(answer == maxx) cout << -1;
    else cout << answer;
}
// Designed and Coded by Congratulation.
// No Name Corporation.Limited.2021.All Rights Reserved.

//#include <bits/stdc++.h>
//#define F first
//#define S second
//#define pii pair<int,int>
//#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
//#define FORN(i, a, b) for(int i = (a); i < (b); ++i)
//#define FORD(i, a, b) for(int i = a; i >=b; --i)
//#define pb push_back
//#define mp make_pair
//#define yes cout <<"YES"<<"\n"
//#define no  cout << "NO"<<"\n"
//#define MOD 1000000007
//#define maxn 2e18
//#define reset(x) memset(x, 0, sizeof(x))
//#define all(x) (x.begin(),x.end())
//#define ll long long
//#define db double
//#define ull unsigned long long
//#define udb unsigned double
//#define ui unsigned int
//#define ldb long double
//#define ulli unsigned long long int
//#define lli long long int
//#define str string
////#define fl Team Flash a nham float
//#define fl float
//#define TASK "A"
//#define int long long
//
// /*
//As a game
//I'll get victory!
//As an experience
//I'll enjoy it.
//As a battle
//I'll be a Strong Warrior.
//*/
//
//using namespace std;
//// ATTEMPED 7.
//int n, m, k, d, Stacia;
//int ans = maxn;
//int f[128][128][40], h[40], loga[40];
//int res[128][128], a[128][128];
//int abc(int u, int l){
//    int p = loga[l];
//    if(l == d)
//        return f[u][Stacia][p + 1];
//    int r = maxn;
//    for(int i = 1; i <= n; i++)
//        if(f[u][i][p + 1] != maxn){
//            int v = res[i][l+1];
//            r = min(r, f[u][i][p + 1] + v);
//        }
//    return r;
//}
//
//signed main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);
//    if(fopen(TASK".inp", "r")) {
//        freopen(TASK".inp","r",stdin);
//        freopen(TASK".out","w",stdout);
//    }
//    cin >> n >> m >> k;
//    for(int i = 1; i <= m; i++){
//        int u, v, w;
//        cin >> u >> v >> w;
//        if(a[u][v] != 0)
//            a[u][v] = min(a[u][v], w);
//        else a[u][v] = w;
//        f[u][v][1] = a[u][v];
//    }
//    h[0] = 1;
//    for(int i = 1; i <= 30; i++)
//        h[i] = h[i-1]*2;
//    while(k > 0){
//        d++;
//        loga[d] = log2(k);
//        k -= 1 << loga[d];
//    }
//    for(int i = 1; i <= n; i++)
//        for(int j = 1; j <= n; j++)
//            if(a[i][j] == 0)
//                f[i][j][1] = maxn;
//    for(int l = 2; l <= 30; l++)
//        for(int i = 1; i <= n; i++)
//            for(int j = 1; j <= n; j++){
//                if(f[i][j][l] == 0)
//                    f[i][j][l] = maxn;
//                for(int p = 1; p <= n; p++)
//                    f[i][j][l] = min(f[i][j][l], f[i][p][l-1] + f[p][j][l - 1]);
//            }
//    for(int i = 1; i <= n; i++){
//        Stacia = i;
//        for(int k = d; k >= 1; k--)
//            for(int j = 1; j <= n; j++)
//                res[j][k] = abc(j, k);
//        ans = min(ans, res[i][1]);
//    }
//    if(ans == maxn) cout << -1;
//    else cout << ans;
//}
//// Designed and Coded by Congratulation.
//// No Name Corporation.Limited.2021.All Rights Reserved.
