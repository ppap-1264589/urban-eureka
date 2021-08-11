#include <bits/stdc++.h>

#define Task                    "B"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
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
int sp[18][maxn];
int v,k;
//int f[i][x] == la cha cua x cach x 2^i buoc
//int v = f[i-1][u];

///precompute O(NlogN)
///Access     O(logN)
void Sparse(){
    for (int i = 1; i <= log2(n); i++){
        for (int u = 1; u <= n; u++){
            int v = sp[i-1][u];
            sp[i][u] = sp[i-1][v];
        }
    }
}

void Out(){
    for (int i = 17; i >= 0; i--){
        if (bit(k, i)){
            v = sp[i][v];
        }
    }
    cout << v << "\n";
}


signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    up(i, 2, n){
        cin >> sp[0][i];
    }
    Sparse();

    up(i, 1, m){
        cin >> v >> k;
        Out();
    }

//    for (int i = 0; i <= 17; i++){
//        for (int j = 0; j <= 20; j++){
//            cout << sp[i][j] <<  " ";
//        }
//        cout << "\n";
//    }

    return 0;
}
