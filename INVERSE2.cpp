#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "INVERSE2"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     14062008
#define ll                      long long
#define trail0(x)               (x & (-x))

using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

int a[100001];
int BIT[100001];
int n;
long long res;

void update(int x){
    while (x > 0){
        BIT[x] += 1;
        x -= trail0(x);
    }
}

void Get(int x){
    while (x <= n){
        res += BIT[x];
        x += trail0(x);
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
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    compress();
    up(i, 1, n){
        update(a[i]);
        Get(a[i]+1);

//        for (int j = 1; j <= n; j++) cout << BIT[j] << " ";
//        cout << "\n";
    }
    cout << res;
    return 0;
}
