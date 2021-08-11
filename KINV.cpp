#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "KINV"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000000
#define ll                      long long
#define trail0(x)               (x & (-x))
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
int n,k;
int a[maxn];
int f[11][maxn];
int BIT[maxn];

void compress(){
    vector<int> v;
    v.assign(a+1, a+n+1);
    sort(v.begin(), v.end());
    up(i, 1, n){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
}

int getlen (int x){
    int res = 0;
    while (x > 0){
        res = (res + BIT[x]) % MOD;
        x -= trail0(x);
    }
    return res;
}

void update(int x, int val){
    while (x <= n){
        BIT[x] = (BIT[x] + val) % MOD;
        x += trail0(x);
    }
}

///From VNOI with love
// Goi f[x][i] la day con tang co do dai x ket thuc tai vi tri i
// Goi BIT[x] la do dai day con tang co (do dai dang xet) ket thuc tai gia tri x

// Voi x = 1 => f[x][i] = 1 voi moi i
// Voi x >= 2 dung LIS thong thuong
    // update a[j] cung gia tri toi uu truoc do f[i-1][j]

void add(int& a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    up(i, 1, n) cin >> a[i];
    //compress();

    up(i, 1, n){
        f[1][i] = 1;
    }
    up(i, 2, k){
        fill(BIT, BIT+n+1, 0);
        down(j, n, 1){ // Tai sao for nguoc lai dung ??
            f[i][j] = getlen(a[j]); // Tai sao -1 hay khong van co ket qua dung ??
            update(a[j], f[i-1][j]);
        }
    }

    int res = 0;
    up(i, 1, n){
        add(res, f[k][i]);
    }
    cout << res;

//    cout << "\n";
//    up(i, 1, k){
//        up(j, 1, n){
//            cout << f[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//
//    up(i, 1, n){
//        cout << BIT[i] << " ";
//    }
//    cout << "\n";
    return 0;
}
