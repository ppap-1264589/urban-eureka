#include <bits/stdc++.h>
#define pii pair<double, double>
#define x first
#define y second
using namespace std;

const int maxn = 1001;
pii a[maxn];
int n;

double sqr(double t){
    return t*t;
}

double radius(double x){
    double y = 0;
    for (int i = 1; i <= n; i++){
        y = max(y, (sqr(x - a[i].x) + sqr(a[i].y))/(2.0 * a[i].y));
    }
    return y;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("A.inp", "r")){
        freopen ("A.inp", "r", stdin);
        freopen ("A.out", "w", stdout);
    }

    double l = -2e6;
    double r = 2e6;
    double ACRC = 1e-6;

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }

    while (r - l > ACRC){
        double mid1 = l + (r - l)/3;
        double mid2 = r - (r - l)/3;
        if (radius(mid1) < radius(mid2)) r = mid2;
        else l = mid1;
    }
    cout << fixed << setprecision(3) << radius(l);
}
