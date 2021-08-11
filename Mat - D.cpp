#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("avx2")

#define Task                    "D"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int MOD = 666013;

int n,h,k;
struct Matrix{
    long long val[102][102];
};

Matrix nhan(Matrix a, Matrix b){
    Matrix res;
    for (int i = 0; i <= h; i++){
        for (int j = 0; j <= h; j++){
            res.val[i][j] = 0;
            for (int k = 0; k <= h; k++){
                res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix power(Matrix res, long long d){
    if (d == 1) return res;
    Matrix T = power(res, d/2);
    if (d % 2 == 0) return nhan(T, T);
    return nhan(nhan(T, T), res);
}

Matrix A;
signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h >> k;
    for (int i = 0; i <= h; i++){
        for (int j = max(0, i-k); j <= min(h, i+k); j++){
            A.val[i][j] = 1;
        }
    }

    for (int i = 0; i <= h; i++){
        for (int j = 0; j <= h; j++){
            cout << A.val[i][j] << " ";
        }
        cout << "\n";
    }

    A = power(A, n-1); // Do day bat dau tu 1, nen bieu thuc xac dinh la F[n] = T^(n-1) * F[1]
    cout << A.val[h][0];

    cout << "\n";
    for (int i = 0; i <= h; i++){
        for (int j = 0; j <= h; j++){
            cout << A.val[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}



