#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "SBOX2"
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
int n,m;
int l, r, d;
int a[maxn];
int BIT[maxn];

void add(int x, int val){
    while (x <= n){
        BIT[x] += val;
        x += (x & -x);
    }
}

void update(int l, int r, int val){
    add(l, val);
    add(r+1, -val);
}

int point_query(int x){
    int ans = 0;
    while (x > 0){
        ans += BIT[x];
        x -= (x & -x);
    }
    return ans;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while (m--){
        int c;
        cin >> c;
        if (c == 1){
            cin >> l >> r >> d;
            update(l, r, d);
        }
        else {
            int x;
            cin >> x;
            cout << point_query(x) << "\n";
        }
    }
    return 0;
}
