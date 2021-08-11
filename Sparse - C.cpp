#include <bits/stdc++.h>

#define Task                    "C"
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

const int maxn = 501;
int n,m;
int u,v,p,q;
int sp[9][9][maxn][maxn];


void Init(){
    cin >> n >> m;
    up(i, 1, n){
        up(j, 1, m){
            cin >> sp[0][0][i][j];
        }
    }

    up(u, 1, n){
        up(j, 1, 8){
            for (int v = 1; v + (1 << j) - 1 <= m; v++){
                sp[0][j][u][v] = min(sp[0][j-1][u][v], sp[0][j-1][u][v + (1 << (j-1))]);
            }
        }
    }

    up(i, 1, 8){
        up(j, 0, 8){
            for (int u = 1; u + (1 << i) - 1 <= n; u++){
                for (int v = 1; v + (1 << j) - 1 <= m; v++){
                    sp[i][j][u][v] = min(sp[i-1][j][u][v], sp[i-1][j][u + (1 << (i-1))][v]);
                }
            }
        }
    }
}

void getmin(int u, int v, int p, int q){
    int k = log2(p-u+1);     //do dai hang
    int l = log2(q-v+1);     //do dai cot
    int r = p - (1 << k) + 1;
    int s = q - (1 << l) + 1;
    int m1 = sp[k][l][u][v];
    int m2 = sp[k][l][u][s];
    int m3 = sp[k][l][r][v];
    int m4 = sp[k][l][r][s];

    cout << min(min(min(m1, m2), m3), m4) << "\n";
}


signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Init();
    int tt;
    cin >> tt;
    while (tt--){
        cin >> u >> v >> p >> q;
        getmin(u,v,p,q);
    }
    return 0;
}
