#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define Task                    "SNOW_WH"
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

const int maxn = 200001;
int n,m;
int h[maxn];
int p[maxn];
int u,v;

struct ST{
    int T[maxn*4], a[maxn], id[maxn];

    void build(int nod, int l, int r){
        if (l == r){
            T[nod] = a[r];
            id[r] = nod;
            return;
        }
        int mid = (l+r)/2;
        build(nod*2, l, mid);
        build(nod*2+1, mid+1, r);
        T[nod] = min(T[nod*2], T[nod*2+1]);
    }

    void update(int pos, int val){
        int nod = id[pos];
        T[nod] = a[pos] = val;

        while (nod > 1){
            nod /= 2;
            T[nod] = min(T[nod*2], T[nod*2+1]);
        }
    }

    int getmin(int nod, int l, int r){
        if (v < l || u > r) return INT_MAX;
        if (l >= u && r <= v) return T[nod];
        int mid = (l+r)/2;
        int left = getmin(nod*2, l, mid);
        int right = getmin(nod*2+1, mid+1, r);
        return min(left, right);
    }
};

ST Tmin, Tmax;
signed main(){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    up(i, 1, n) cin >> h[i];
    up(i, 1, n) p[h[i]] = i;
    up(i, 1, n){
        Tmin.a[i] = p[i];
        Tmax.a[i] = -p[i];
    }

    up(i, 1, n){
        cout << p[i] << " ";
    }
    cout << "\n";

//    up(i, 1, n){
//        cin >> h[i];
//        p[h[i]] = i;
//    }
//    up(i, 1, n){
//        cout << p[i] << " ";
//    }
//    cout << "\n";

    Tmin.build(1, 1, n);
    Tmax.build(1, 1, n);

    while (m--){
        int c;
        cin >> c >> u >> v;
        if (c == 1){
            Tmin.update(h[u], v);
            Tmin.update(h[v], u);
            Tmax.update(h[u], -v);
            Tmax.update(h[v], -u);

//            Tmin.update(u, h[v]);
//            Tmin.update(v, h[u]);
//            Tmax.update(u, -h[v]);
//            Tmax.update(v, -h[u]);
            swap(h[u], h[v]);
        }
        else {
            int minh = Tmin.getmin(1,1,n);
            int maxh = -Tmax.getmin(1,1,n);
            if (maxh - minh == v - u) cout << "YES";
            else cout << "NO";
            cout << "\n";
        }
    }
    return 0;
}
