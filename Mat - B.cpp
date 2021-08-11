#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("avx2")

#define Task                    "B"
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

/**
f[i]   = f[i-1] + f[i-2] + f[i-3]
f[i-1] = f[i-1]
f[i-2] = f[i-2]
**/
long long n,M;
struct Matrix{
    long long c[3][3];
    Matrix(){
        c[0][0] = 1;        c[0][1] = 1;        c[0][2] = 1;

        c[1][0] = 1;        c[1][1] = 0;        c[1][2] = 0;

        c[2][0] = 0;        c[2][1] = 1;        c[2][2] = 0;
    }
    ~Matrix(){};
}; Matrix A;

Matrix nhan(Matrix a, Matrix b){
    Matrix res;
    for (int i = 0; i <= 2; i++){
        for (int j = 0; j <= 2; j++){
            res.c[i][j] = 0;
            for (int k = 0; k <= 2; k++){
                res.c[i][j] = ((res.c[i][j] % M) + (a.c[i][k]*b.c[k][j] % M)) % M;
            }
        }
    }
    return res;
}

Matrix power(Matrix res, long long n){
    if (n == 1) return res;
    if (n % 2 == 1){
        Matrix T = power(res, n/2);
        return nhan(nhan(T, T), res);
    }
    Matrix T = power(res, n/2);
    return nhan(T, T);
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> M;

    A = power(A, n);
    cout << A.c[0][0];
    return 0;
}
