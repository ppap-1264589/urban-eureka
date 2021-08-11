#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("avx2")

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

/**

F[i] = F[i-1] + 2*F[i-2]         [1, 2]
F[i-1] = F[i-1]                  [1, 0]

**/

struct Matrix{
    long long c[3][3];
    Matrix(){
        memset(c, 0, sizeof(c));
    }

    static Matrix unit(){
        Matrix x;
        x.c[0][0] = x.c[1][1] = 1;
        return x;
    }

    Matrix operator * (const Matrix& b){
        Matrix res;
        for (int i = 0; i <= 1; i++){
            for (int j = 0; j <= 1; j++){
                for (int k = 0; k <= 1; k++){
                    res.c[i][j] = (res.c[i][j] + c[i][k] * b.c[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix Poww(long long n){
        Matrix res = unit();
        if (n == 0) return res;
        Matrix T = Poww(n/2);
        res = T*T;
        if (n % 2 == 1) res = res * (*this);
        return res;
    }
};

long long n;
signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    n += 2;
    Matrix T;
    T.c[0][0] = 1;
    T.c[0][1] = 1;
    T.c[1][0] = 1;
    T.c[1][1] = 0;
    Matrix A = T.Poww(n);
    cout << A.c[0][0] - 1 << "\n";
    return 0;
}
