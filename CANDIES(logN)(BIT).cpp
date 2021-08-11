#include <bits/stdc++.h>

#define Task                    "CANDIES"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     14062008
#define ll                      long long
#define trail0(x)               (x & (-x))
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
int BIT[maxn]; // How many candies eaten
int a[maxn];

int Find(int x){ // Find lowest i in a[] such that a[i] >= x
    int pos = 0; // Target pos
    int sum = 0; // Prefix sum
    for (int i = log2(n); i >= 0; i--){
        int bi = pos + (1 << i);
        if (bi <= n && a[bi] - (sum + BIT[bi]) < x){
            pos = bi; // liftup
            sum += BIT[bi];
        }
    }
    return pos+1;
}

void update(int x){
    while (x <= n){
        BIT[x] += 1;
        x += trail0(x);
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    cin >> m;
    up(i, 1, m){
        int x;
        cin >> x;
        int t = Find(x);
        cout << (n-t+1) << "\n";
        update(t);
    }
    return 0;
}

/// Exponential search
/// reference : https://codeforces.com/blog/entry/61364
