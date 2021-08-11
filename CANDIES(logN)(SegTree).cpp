#include <bits/stdc++.h>

#define Task                    "CANDIES"
#define bit(x,i)                (x & (1 << (i)))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
using namespace std;

const int maxn = 100001;
int n,m;
int a[maxn];
int T[maxn*4];
int d[maxn*4];
int x;
int u,v;

void build(int nod, int l, int r){
    if (l == r) {
        T[nod] = a[r];
        return;
    }
    int mid = (l+r)/2;
    build(nod*2, l, mid);
    build(nod*2+1, mid+1, r);
    T[nod] = max(T[nod*2], T[nod*2+1]);
}

void lazypush(int nod){
    int t = d[nod];
    int k = nod*2;
    d[k] += t;
    d[k+1] += t;
    T[k] += t;
    T[k+1] += t;

    d[nod] = 0;
}

void upd(int nod, int l, int r, int w){
    if (r < u || l > v) return;
    if (l >= u && r <= v){
        T[nod] += w;
        d[nod] += w;
        return;
    }

    lazypush(nod);

    int mid = (l+r)/2;
    upd(nod*2, l, mid, w);
    upd(nod*2+1, mid+1, r, w);
    T[nod] = max(T[nod*2], T[nod*2+1]) + d[nod];
}

int Find(int nod, int l, int r){ // Quy uoc, vi tri can tim la r
//    cout << nod << " ";
                                // l, r la doan tim nhi phan
                                // (Thoa man): luong keo trong hop co lon hon x?
    if (l == r) return r;       // Node chi quan ly 1 phan tu duy nhat -> r la dap an
    if (T[nod] < x) return r+1; // Neu khoang dang xet khong thoa man -> Toi da la an keo duoc den r+1
    // Neu no thoa man ? Bin search: Lieu ta co the an keo nhieu hon ma van thoa man?
    lazypush(nod);

    /// KINH DIEN : Chi lazypush khi can thiet, khi ta van co the de quy xuong cac nut con duoc
    /// Neu lazypush tuy tien ? -> cac node duoc push khong can thiet,
    ///                         -> Khi (l == r), chi so node duoc push co the len den 8N  !! -> RTE
    int mid = (l+r)/2;
    if (T[nod*2] < x)
    return Find(nod*2+1, mid+1, r);
    return Find(nod*2, l, mid);
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    up(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    build(1,1,n);
    cin >> m;
    up(i, 1, m){
        cin >> x;
        int t = Find(1,1,n);
        cout << (n-t+1);
        cout << "\n";
        u = t;
        v = n;
        upd(1,1,n, -1);
    }
    return 0;
}
