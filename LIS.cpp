#include <bits/stdc++.h>

#define Task                    "LIS"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     14062008
#define ll                      long long

using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 100001;
int n;
int a[maxn];
int BIT[maxn];
int dp[maxn];

//dp[i] do dai LIS ket thuc tai vi tri i
//BIT[x] do dai LIS ket thuc tai gia tri x


int getmax(int x){
    int ans = 0;
    while (x > 0){
        ans = max(ans, BIT[x]);
        x -= (x & -x);
    }
    return ans;
}
//
void update(int x, int val){
    while (x <= n){
        BIT[x] = max(BIT[x], val);
        x += (x & -x);
    }
}

void compress(){
    vector<int> v;
    v.assign(a+1, a+n+1);
    sort(v.begin(), v.end());
    up(i, 1, n){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    compress();

    up(i, 1, n){
        int lmax = getmax(a[i]-1);
        dp[i] = lmax + 1;
        update(a[i], dp[i]);
    }

//    up(i, 1, n){
//        cout << BIT[i] << " ";
//    }
//    cout << "\n";
//    up(i, 1, n){
//        cout << dp[i] << " ";
//    }

    cout << *max_element(dp+1, dp+n+1);
    return 0;
}
