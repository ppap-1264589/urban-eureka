///Template created by PPAP_1264589
#include <bits/stdc++.h>
#define Task              "HISTOGRAM"
#define ll                long long
#define rollup(i,a,b)     for (int i = (a); i <= (b); i++)
#define bit(x, i)         ((x >> (i)) & 1)
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

int n;
int a[16];
ll f[1 << 15][16];
ll g[1 << 15][16];
ll maxx;
ll res;

int Get_add(int le, int ri){
    if (le > ri) return 0;
    return (ri - le) * 2;
}

void dp_bit(){
    maxx = INT_MIN;
    rollup(i, 0, n-1){
        cin >> a[i];
        f[(1 << i)][i] = 2 * a[i];
        g[(1 << i)][i] = 1;
    }
    rollup(x, 0, (1 << n) - 1){
        rollup(i, 0, n-1){
            if (bit(x, i))
            rollup(j, 0, n-1){
                if (bit(x, j)){
                    int y = (x &~ (1 << j));
                    int len = Get_add(a[i], a[j]);
                    int C = len + f[y][i];
                    if (f[x][j] < C){
                        f[x][j] = C;
                        g[x][j] = g[y][i];
                    }
                    else if (f[x][j] == C){
                        g[x][j] += g[y][i];
                    }
                }
            }
        }
    }
//    rollup(i, 0, (1 << n)-1){
//        rollup(j, 0, n-1){
//            cout << f[i][j] << " ";
//        }
//        cout << "\n";
//    }

    rollup(i, 0, n-1) maxx = max(maxx, f[(1 << n)-1][i]);
    int l = (1 << n) - 1;
    res = 0;
    rollup(i, 0, n-1){
        if (f[l][i] == maxx) res += g[l][i];
    }
}

int main (){
    setFile();
    while (cin >> n && n != 0){
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        dp_bit();
        cout << maxx + n*2 << " " << res << "\n";
    }
    return 0;
}