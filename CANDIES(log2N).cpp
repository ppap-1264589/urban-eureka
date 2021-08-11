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
int a[maxn];
int t[maxn];
int BIT[maxn];

void compress(int q[], int l){
    vector<int> v;
    v.assign(q+1, q+l+1);
    sort(v.begin(), v.end());
    up(i, 1, l){
        q[i] = lower_bound(v.begin(), v.end(), q[i]) - v.begin() + 1;
    }
}

int get(int x){
    int res = 0;
    while (x > 0){
        res += BIT[x];
        x -= trail0(x);
    }
    return res;
}

void update(int x, int val){
    while (x <= n){
        BIT[x] += val;
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
    up(i, 1, m) cin >> t[i];

//    compress(a, n);
//    compress(t, m);

    sort(a+1, a+n+1, greater<int>());

    up(i, 1, m){
        int r = n+1;
        int l = 0;
        while (r - l > 1){
            int mid = (l+r)/2;
            if (a[mid] - get(mid) < t[i]) r = mid;
            else l = mid;
        }
        cout << r-1 << "\n";
        update(l+1, -1);
        update(1, 1);
    }
//    up(i, 1, n) cout << BIT[i] << " ";
    return 0;
}
