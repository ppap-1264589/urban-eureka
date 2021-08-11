#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task            "SEQ2015"
#define up(i,a,b)       for (int i = (a); i <= (b); i++)
using namespace std;

const int maxn = 100001;
int n;
int a[maxn];
int dp[701][701];

void add(int& a, int b){
    a = a + b;
    if (a >= 30103) a -= 30103;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n;
    up(i, 1, n) cin >> a[i];
    int res = 0;

    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            for (int p = i+1; p < j; p++){
                for (int q = j-1; q > p; q--){
                    if (a[p] + a[q] < a[i] + a[j]){
                        add(dp[p][q], dp[i][j] + 1);
                    }
                }
            }
        }
    }

//    up(i, 1, n){
//        up(j, 1, n){
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }
    up(i, 1, n){
        up(j, 1, n){
            add(res, dp[i][j]);
        }
    }
    cout << res;
    return 0;
}
