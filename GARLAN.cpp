#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Task "GARLAN"
//http://cpp.sh/2cd2b
using namespace std;
void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

int n,m;
string a[16];
int c[16][16];
int f[1 << 15][16];

void in(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }
}

void initcost(){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            int cost = 0;
            for (int k = 0; k < n; k++){
                cost += a[i][k] ^ a[j][k];
            }
            c[i][j] = cost;
        }
    }
}

void basis(){
    for (int i = 0; i < (1 << m); i++){
        fill(f[i], f[i] + m + 1, 10000001);
    }
    for (int i = 1; i <= m; i++){
        int dem = 0;
        for (int j = 0; j < n; j++){
            if (a[i][j] == '1') dem++;
        }
        f[(1 << (i-1))][i] = dem;
    }
}

void Dp_bit(){
    for (int state = 0; state < (1 << m); state++){
        for (int i = 1; i <= m; i++){
            for (int k = 1; k <= m; k++){
                if (i != k && state >> (i-1) & 1 && state >> (k-1) & 1){
                    f[state][i] = min(f[state][i], f[state - (1 << (i-1))][k] + c[i][k]);
                }
            }
        }
    }
}

int main (){
    IOS
    setFile();
    in();
    initcost();
    basis();
    Dp_bit();
    int minn = INT_MAX;
    for (int i = 1; i <= m; i++){
        minn = min(minn, f[(1 << m) - 1][i]);
    }
    cout << minn;
    return 0;
}
