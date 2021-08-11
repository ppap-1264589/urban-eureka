#include <bits/stdc++.h>

#define Task                    "SUBSEQ"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
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
int n,k;
int a[maxn];
int BIT[maxn];
pair<int, int> T[maxn];

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

void update(int x, pii v){
    while (x <= n){
        if (v.f > T[x].f) T[x] = v;
        else if (v.f == T[x].f) {
            add(T[x].s, v.s);
        }
        x += trail0(x);
    }
}

pii getl(int x){
    pii res = make_pair(0, 1);
    while (x){
        if (res.f < T[x].f) res = T[x];
        else if (res.f == T[x].f){
            add(res.s, T[x].s);
        }
        x -= trail0(x);
    }
    return res;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    up(i, 1, n) cin >> a[i];
    compress();

    pair<int, int> v;
    up(i, 1, n){
        v = getl(a[i]-1);
        update(a[i], make_pair(v.f+1, v.s));
    }
    cout << getl(n).s;
    return 0;
}
