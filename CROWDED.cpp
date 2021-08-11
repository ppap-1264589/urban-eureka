#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("CROWDED.inp", "r", stdin);
    freopen ("CROWDED.out", "w", stdout);
}

int n,d;
pair<int, int> a[50001];
bool l[50001];
bool r[50001];
deque<int> de;

void left(){
    for (int i = 1; i <= n; i++){
        while (!de.empty() && a[de.front()].f + d < a[i].f) de.pop_front(); // con bo dang xet nam ngoai khoang ? - khong xet den
        while (!de.empty() && a[i].s >= a[de.back()].s) de.pop_back();      // con bo dang xet co chieu cao lon hon ca con bo cuoi cung ? - khong tinh
        if (!de.empty() && a[i].s*2 <= a[de.front()].s) l[i] = 1;           // cao hon den muc nao ? (theo de bai) the la ngot ngat ben trai
        de.push_back(i);
    }
}

void right(){
    for (int i = n; i >= 1; i--){
        while (!de.empty() && a[i].f + d < a[de.front()].f) de.pop_front();
        while (!de.empty() && a[i].s >= a[de.back()].s) de.pop_back();
        if (!de.empty() && a[i].s*2 <= a[de.front()].s) r[i] = 1;          // tuong tu: ngot ngat ben phai
        de.push_back(i);
    }
}
int main (){
    setFile();
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].f >> a[i].s;
    }
    sort(a+1, a+n+1);
    left();
    de = deque<int>{};
    right();
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (l[i] && r[i]) res++;
    }
    //for (int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << "\n";
    cout << res;
}
