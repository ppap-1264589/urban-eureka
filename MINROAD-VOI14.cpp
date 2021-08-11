#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

int n;
int a,b;
pii p[300001];

void in(){
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++){
        cin >> p[i].f >> p[i].s;
    }
    sort(p+1, p+n+1);
}

int two_pointer(int n){
    int i = 0;
    int j = 0;
    int minn = INT_MAX;
    int dema = 0;
    int demb = 0;

    while (i <= n && j <= n){
        if (dema < a || demb < b){
            j++;
            if (p[j].s == 1) dema++;
            else demb++;
        }
        else {
            i++;
            if (p[i].s == 1) dema--;
            else demb--;
            minn = min(minn, p[j].f - p[i].f);
        }
    }
    if (minn == INT_MAX) return -1;
    return minn;
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    in();
    cout << two_pointer(n);
    return 0;
}
