//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 200005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "comp_str"

using namespace std;

typedef long long ll;
typedef long double ld;

const int base = 101;

string st;
int a[maxn];
int n;

int len[4*maxn]; // Do dai doan
long long H[4*maxn], mu[maxn];

void Init(int node, int l, int r){
    if (l == r){
        len[node] = 1;
        H[node] = a[l];
        return;
    }

    int mid = (l+r)/2;
    Init(node*2, l, mid);
    Init(node*2+1, mid+1, r);
    len[node] = len[node*2] + len[node*2+1];
    H[node] = H[node*2] * mu[len[node*2+1]] + H[node*2+1];
}

int Get_pos(int node, int l, int r, int pos){
    if (l == r) return l;
    int mid = (l+r)/2;
    if (pos <= len[node*2]) return Get_pos(node*2, l, mid, pos);
    return Get_pos(node*2+1, mid+1, r, pos - len[node*2]);
}

void Xoa(int node, int l, int r, int pos){
    if (l == r) {
        len[node] = 0;
        H[node] = 0;
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid) Xoa(node*2, l, mid, pos);
        else Xoa(node*2+1, mid+1, r, pos);
    len[node] = len[node*2] + len[node*2+1];
    H[node] = H[node*2] * mu[len[node*2+1]] + H[node*2+1];
}

pair <ll, int> Get_hash(int node, int l, int r, int u, int v){
// < ma hash,   do dai giao (l,r) va (u,v)>
    if (u > r || v < l) return mp(0, 0);
    if (l >= u && r <= v) return mp(H[node], len[node]);
    int mid = (l+r)/2;
    pair<ll, int> trai = Get_hash(node*2, l, mid, u, v);
    pair<ll, int> phai = Get_hash(node*2+1, mid+1, r, u, v);
    return mp(trai.F * mu[phai.S] + phai.F, trai.S + phai.S);
}

int Get_pos(int x){
    return Get_pos(1,1,n,x);
	//x <= len[1] -> so luong thang con lai
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> st;
    n = st.length();
    for (int i= 1; i <= n; i++) a[i] = st[i-1] - 48;
    mu[0] = 1;
    for (int i = 1; i <= n; i++) mu[i] = mu[i-1]*base;
    Init(1, 1, n);
    int m;
    cin >> m;
    while (m--){
        int u, v, dai;
        char type;
        cin >> type;
        if (type == '-'){
            cin >> u;
            int x = Get_pos(u);
            Xoa(1, 1, n, x);
        } else {
            cin >> u >> v >> dai;
            int L1 = Get_pos(u), R1= Get_pos(u+dai-1);
            int L2 = Get_pos(v), R2= Get_pos(v+dai-1);
            pair<ll, int> p = Get_hash(1,1,n,L1,R1);
            pair<ll, int> q = Get_hash(1,1,n,L2,R2);
            if (p == q) cout << "YES\n";
                else cout << "NO\n";
        }
    }
    return 0;
}

