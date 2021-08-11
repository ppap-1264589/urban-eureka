///Template created by PPAP_1264589 ↔
#include <bits/stdc++.h>
#define Task              "KPERMS"
#define ll                long long
#define ull               unsigned long long
#define pii               pair<int, int>
#define f                 first
#define s                 second
#define MP                make_pair
#define PB                push_back
#define rollup(i,a,b)     for (int i = (a); i <= (b); i++)
#define rolldown(i,a,b)   for (int i = (a); i >= (b); i--)
#define bit(x, i)         ((x >> (i)) & 1)
#define debug(x)          cerr << #x << " = " << x << "\n";
#define MOD               1e9 + 7
#define all(v)            (v).begin(),(v).end()
using namespace std;
///Template created by PPAP_1264589 ↔

void setFile(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

int n,k;
ll f[1 << 15][16];
//F[x][i] : so cach tao thanh hoan vi o trang thai x co phan tu cuoi cung la i

void dp_bit(){
    rollup(i, 0, n-1) f[1 << i][i] = 1;
    //Co so Quy hoach
    //luon luon co 1 cach de co so i o cuoi
    rollup(st, 0, (1 << n) - 1){
        rollup(i, 0, n-1){
            rollup(j, 0, n-1){
                if (i != j && bit(st, i) && abs(i-j) <= k){
                    f[st][i] += f[st &~ (1 << i)][j];
                }
            }
        }
    }
    rollup(i, 0, (1 << n) - 1){
        rollup(j, 0, n-1){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main (){
    setFile();
    cin >> n >> k;
    dp_bit();
    ll res = 0;
    rollup(i, 0, n-1){
    // tong so cach co hoan vi thoa man
    //ket thuc tai i
        res += f[(1 << n) - 1][i];
    }
    cout << res;
    return 0;
}

/// WARNING : ??!!
/*
    * int overflow ?
    * array bounds ?
    * special cases (n = 1, n = 0) ?
    * uncontrolled loop ?
    * int or long long ?
    * positive or negative ?
    * divided by 0 ?
    * reset ?
*/

//hoặc f[x][i] <-- f[x-2^i][j]
//với j tồn tại trong x và khác i
