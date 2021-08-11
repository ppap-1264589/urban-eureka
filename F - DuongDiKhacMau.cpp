#include <bits/stdc++.h>
#define up(i, a, b) for (int i = (a); i <= (b); i++)
#define bit(x, i) ((x >> i) & 1)
#define emplace_back ep
using namespace std;

const int maxn = 100001;
int n,m,k;
int c[maxn];
vector<int> a[maxn];
long long F[1 << 6][maxn];

signed main(){
    if (fopen("A.inp", "r")){
        freopen ("A.inp", "r", stdin);
        freopen ("A.out", "w", stdout);
    }

    scanf("%d%d%d", &n, &m, &k);
    up(i, 0, n-1){
        scanf("%d", &c[i]);
        c[i]--;
    }
    int u,v;
    up(i, 1, m){
        scanf("%d%d", &u, &v);
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    up(i, 0, n-1){
        F[1 << c[i]][i] = 1;
    }

    up(x, 0, (1 << k)-1){
        up(u, 0, n-1){
            for (auto v : a[u]){
                if (bit(x, c[v]) == 0){
                    F[x | (1 << c[v])][v] += F[x][u];
                }
            }
        }
    }

//    up(i, 0, (1 << k) - 1){
//        cout << i << " ";
//        up(j, 0, n-1){
//            printf("%d ", F[i][j]);
//        }
//        printf("\n");
//    }

    long long res = 0;
    up(i, 0, n-1){
        up(x, 0, (1 << k)-1){
            if (__builtin_popcount(x) >= 2) res += F[x][i];
        }
    }
    cout << res;
}
