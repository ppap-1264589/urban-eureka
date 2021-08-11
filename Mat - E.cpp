#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "E"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define base                    311
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

long long n,k;
long long c[103];

struct Matrix{
    long long val[103][103];
}; Matrix Final;

Matrix nhan(Matrix a, Matrix b){
    Matrix res;
    for (int i = 0; i <= 100; i++){
        for (int j = 0; j <= 100; j++){
            res.val[i][j] = 0;
            for (int k = 0; k <= 100; k++){
                res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix Power(Matrix a, long long n){
    if (n == 1) return a;
    Matrix T = Power(a, n/2);
    if (n % 2 == 0) return nhan(T, T);
    return nhan(nhan(T, T), a);
}

void Init(){
    Final.val[0][0] = 1;
    Final.val[0][1] = Final.val[1][1] = c[1];
    for (int i = 2; i <= 100; i++){
        Final.val[i][i-1] = 1;
        Final.val[0][i] = Final.val[1][i] = c[i];
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        c[x]++;
    }
    Init();
//    for (int i = 0; i <= 100; i++){
//        for (int j = 0; j <= 100; j++){
//            cout << Final.val[i][j] << " ";
//        }
//        cout << "\n";
//    }

    Final = Power(Final, k);

//    for (int i = 0; i <= 100; i++){
//        for (int j = 0; j <= 100; j++){
//            cout << Final.val[i][j] << " ";
//        }
//        cout << "\n";
//    }
    cout << (Final.val[0][0] + Final.val[0][1]) % MOD;
    return 0;
}
