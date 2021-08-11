#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<double, double>
using namespace std;

const int maxn = 100001;
pii a[maxn];
int u,v;
int n;

void in(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> u >> v;
        a[i].x = u;
        a[i].y = v;
    }
}

bool check(double r){
    for (int i = 1; i <= n; i++){
        if (a[i].y > r*2) return 0;
    }
    double p;
    double q;
    double L = -1e24;
    double R = 1e24;
    for (int i = 1; i <= n; i++){
        double d = a[i].y * (2*r - a[i].y);
        d = sqrt(d);
        p = a[i].x - d;
        q = a[i].x + d;
        L = max(L, p);
        R = min(R, q);
    }
    return (L <= R); // co diem chung
}

double Search(){
    double l = 0;
    double r = 1e12;
    double ACRC = 1e-7;
    while (r - l > ACRC){
        double mid = (l+r)/2;
        if (check(mid)) r = mid; // tim ban kinh nho nhat
        else l = mid;
    }
    return r;
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
    cout << fixed << setprecision(3);
    cout << Search();
}
