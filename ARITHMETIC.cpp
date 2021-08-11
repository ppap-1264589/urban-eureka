#include <bits/stdc++.h>

#define Task                    "ARITHMETIC"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define ll                      long long
#define pii                     pair<int, int>
#define f                       first
#define s                       second
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}
const int maxn = 100001;
pii T[maxn*4];
int a[maxn];
int id[maxn];
int u,v,w;
int A,B;
int n;

void build(int nod, int l, int r){
    T[nod] = make_pair(1, 0);
    if (l == r){
        id[r] = nod;
        return;
    }
    int mid = (l+r)/2;
    build(nod*2, l, mid);
    build(nod*2+1, mid+1, r);
}

void lazypush(pii x, pii& y){ //We can see the importance of "passing by reference"
    /* Cha : tinh nhan a
             tinh cong b
       Con : tinh nhan c
             tinh cong d
       Cha -> Con: c = c*a
                   d = b*c + d
    */
    y.f = (1ll*x.f * y.f) % MOD;
    y.s = ((1ll*x.f*y.s) % MOD + x.s) % MOD;
}

void update(int nod, int l, int r){
    if (v < l || u > r) return;
    if (l >= u && r <= v){
        if (A == 1){
            T[nod].s = (T[nod].s + B) % MOD;
        }
        else {
            //(x+y)*g -> xg + gy
            T[nod].f = (1ll * T[nod].f * A) % MOD;
            T[nod].s = (1ll * T[nod].s * A) % MOD;
        }
        return;
    }

    lazypush(T[nod], T[nod*2]);
    lazypush(T[nod], T[nod*2+1]);
    T[nod] = make_pair(1,0);
    int mid = (l+r)/2;
    update(nod*2, l, mid);
    update(nod*2+1, mid+1, r);
}

ll getpos(int pos){
    int nod = id[pos];
    long long res = a[pos];

    while (nod > 0){
        res = ((1ll* res * T[nod].f) % MOD + T[nod].s) % MOD;
        nod /= 2;
    }
    return res;
}

void pr_mb(){
    up(i, 1, n*4) cout << T[i].f << " " << T[i].s << "\n";
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    build(1,1,n);
    int q;
    cin >> q;
    while (q--){
        char c;
        cin >> c;
        if (c == '?'){
            int x;
            cin >> x;
            cout << getpos(x) << "\n";
        }
        else {
            cin >> u >> v >> w;
            if (c == '*'){
                A = w;
                B = 0;
                update(1,1,n);
            }
            else {
                A = 1;
                B = w;
                update(1,1,n);
            }
        }
    }
    return 0;
}
