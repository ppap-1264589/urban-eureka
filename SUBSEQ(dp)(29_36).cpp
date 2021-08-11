#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "SUBSEQ"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
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
int dp[maxn];
int cp[maxn];

void compress(){
    vector<int> v;
    v.assign(a+1, a+n+1);
    sort(v.begin(), v.end());
    up(i, 1, n){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
}

void add(int& a, int b){
    a = a + b;
    if (a >= MOD) a -= MOD;
}
void DP(){
    fill(dp, dp+maxn, 1);
    fill(cp, cp+maxn, 1);
    up(i, 1, n){
        up(j, 1, i-1){
            if (a[j] < a[i]){
                if (dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    cp[i] = cp[j];
                }
                else if (dp[i] == dp[j] + 1)
                    add(cp[i], cp[j]);
            }
        }
    }

    int res = 0;
    int lmax = *max_element(dp+1, dp+n+1);
    up(i, 1, n){
        if (dp[i] == lmax) add(res, cp[i]);
    }
    cout << res;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    up(i, 1, n) cin >> a[i];
    compress();
    DP();
    return 0;
}
