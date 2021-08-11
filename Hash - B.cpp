#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "B"
#define ll                      long long
#define bit(x,i)                (x & (1 << (i)))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define base                    3956221
#define pii                     pair<int, int>
#define f                       first
#define s                       second
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 1000001;
const long long MM = 1ll*MOD*MOD;
int n,m;
string s;
pii S[maxn];
pii R[maxn];
int res[100008];

long long gethash(string t){
    long long vhash = 0;
    int nn = t.size();
    t = '@' + t;
    for (int i = 1; i <= nn; i++){
        vhash = (vhash*base + t[i]) % MOD;
    }
    return vhash;
}

//bool cmp1(pii x, pii y){
//    if (x.f == y.f) return (x.s < y.s);
//    return (x.f < y.f);
//}

bool cmp2(pii x, pii y){
    if (x.f == y.f) return (x.s > y.s);
    return (x.f < y.f);
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> s;
    s = '@' + s;
    int u = n/m;
    string a;
    int dem = 1;
    for (int i = 1; i <= n; i += u){
        a = s.substr(i, u);
        S[dem] = make_pair(gethash(a), dem);
        dem++;
    }

    dem = 0;
    for (int i = 1; i <= m; i++){
        string x;
        cin >> x;
        R[i] = make_pair(gethash(x), i);
    }

    sort(S+1, S+m+1);
    sort(R+1, R+m+1, cmp2);

//    up(i, 1, m) {
//        cout << S[i].f << " " << S[i].s << "\n";
//    }
//    cout << "\n";
//
//    for (int i = 1; i <= m; i++){
//        cout << R[i].f << " " << R[i].s << "\n";
//    }
//    cout << "\n";


    up(i, 1, m){
        res[S[i].s] = R[i].s;
    }

    up(i, 1, m){
        cout << res[i] << " ";
    }

    return 0;
}


