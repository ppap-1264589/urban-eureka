#include <bits/stdc++.h>

#define Task                    "A"
#define ll                      long long
#define bit(x,i)                (x & (1 << (i)))
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

const int maxn = 100001;
int n,m;
int sp[maxn][17];
int l,r;

// [i, i + 2^j - 1]
// => [i, i + 2^(j-1) - 1] hop voi [i + 2 ^ (j-1), i + 2^j - 1]

void Sparse(){
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 1; i + (1 << j) - 1 <= n; i++){
            sp[i][j] = min(sp[i][j-1], sp[i + (1 << (j-1))][j-1]);
        }
    }
} // Dua vao hai doan con co do dai 2^log2(r-l+1) phu het [i, j]

void Out(){
    int k = log2(r - l + 1);
    int res = min(sp[l][k], sp[r - (1 << k) + 1][k]);
    cout << res << "\n";
}

void Debug(){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= log2(n); j++){
            cout << sp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    up(i, 1, n) cin >> sp[i][0];
    Sparse();
    while (m--){
        cin >> l >> r;
        Out();
    }
    //Debug();
    return 0;
}
