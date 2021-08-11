#include <bits/stdc++.h>
#define Task "A"
using namespace std;

const int maxn = 100001;

double x[maxn];
double v[maxn];
int n, xx, vv;

double get_dist(double t){
    double dmax = -1.0;
    double dmin = 2e14;
    for (int i = 1; i <= n; i++){
        double d = x[i] + v[i] * t;
        dmax = max(dmax, d);
        dmin = min(dmin, d);
    }
    return (dmax - dmin);
}

pair<double, double> Search(){
    double l = 0;
    double r = 1e7;
    //truong hop xau nhat :
    // 2 nguoi
    // 1 nguoi dung yen
    // 1 nguoi di chuyen 1m/s
    // => WORST_TIME = 1e7
    double ACRC = 1e-9;
    //ACRC vua du
    for (int i = 1; i <= 400; i++){
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        double d1 = get_dist(m1);
        double d2 = get_dist(m2);
        if (d1 < d2 + ACRC) r = m2;
        else l = m1;
    }
    return make_pair(l, get_dist(l));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> xx >> vv;
        x[i] = xx;
        v[i] = vv;
    }

    pair<double, double> res = Search();
    cout << fixed << setprecision(6);
    cout << res.first << " " << res.second;
    return 0;
}
