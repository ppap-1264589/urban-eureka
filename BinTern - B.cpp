#include <bits/stdc++.h>
#define pii pair<double, double>
#define f first
#define s second
using namespace std;

const int maxn = 100001;
pii a[maxn];
int n;
double w,h;
int u,v;
double Md;
double Mc;

void in(){
    cin >> n >> w >> h;

    for (int i = 1; i <= n; i++) {
        cin >> u >> v;
        a[i].f = u;
        a[i].s = v;
        Md = max(Md, w/(1.0*u));
        Mc = max(Mc, w/(1.0*v));
    }
}

bool check(double k){
    double sumh = 0.0;
    double remain = 0;
    for (int i = 1; i <= n; i++){
        if (a[i].s == a[i-1].s && a[i].f*k <= remain){
            remain -= a[i].f*k;
            //neu mot dong co nhieu tu
            //thi cac tu phai duoc in cung 1 do cao
        }
        else{
            sumh += a[i].s*k;
            if (sumh > h) return false;
            remain = w - a[i].f*k;
        }
    }
    return true;
}

double Search(){
    double l = 0;
    double r = min(Mc, Md);
    double ACRC = 1e-7;
    while (r - l > ACRC){
        double mid = (l+r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("A.inp", "r")){
        freopen ("A.inp", "r", stdin);
        freopen ("A.out", "w", stdout);
    }

    in();
    cout << fixed << setprecision(6);
    cout << Search();
}
