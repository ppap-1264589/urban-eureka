#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("avx2")

#define Task                    "A"
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

/**

F[i-1]   =   0*F[i-2] + F[i-1]        [0, 1]
F[i]     =   2*F[i-2] + F[i-1]        [2, 1]

**/

struct Matrix{
    long long c[3][3];
    Matrix(){
        c[0][0] = 0;
        c[0][1] = 1;
        c[1][0] = 2;
        c[1][1] = 1;
    }
    ~Matrix(){};
};


Matrix nhan(Matrix a, Matrix b){
    Matrix res;
    for (int i = 0; i <= 1; i++){
        for (int j = 0; j <= 1; j++){
            res.c[i][j] = 0;
            for (int k = 0; k <= 1; k++){
                res.c[i][j] = (res.c[i][j] + a.c[i][k] * b.c[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix Powermod(Matrix res, long long n){
    if (n == 1) return res;
    if (n % 2 == 1){
        Matrix T = Powermod(res, n/2);
        return nhan(nhan(T, T), res);
    }
    Matrix T = Powermod(res, n/2);
    return nhan(T, T);
}

long long n;
signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--){
        cin >> n;
        Matrix A;
        A = Powermod(A, n);
        cout << A.c[1][1] << "\n";
    }
    return 0;
}
