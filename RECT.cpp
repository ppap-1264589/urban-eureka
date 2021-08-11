#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[1000001];
long long b[1000001];
int ll[1000001];
int rr[1000001];
int ll1[1000001];
int rr1[1000001];
stack<int> sk;

void left(){
    for (int i = 1; i <= n; i++){
        while (!sk.empty() && a[i] <= a[sk.top()]) sk.pop();
        if (sk.empty()) ll[i] = 0;
        else ll[i] = sk.top();
        sk.push(i);
    }
}

void right(){
    for (int i = n; i >= 1; i--){
        while (!sk.empty() && a[i] <= a[sk.top()]) sk.pop();
        if (sk.empty()) rr[i] = n+1;
        else rr[i] = sk.top();
        sk.push(i);
    }
}

void left2(){
    for (int i = 1; i <= n; i++){
        while (!sk.empty() && b[i] <= b[sk.top()]) sk.pop();
        if (sk.empty()) ll1[i] = 0;
        else ll1[i] = sk.top();
        sk.push(i);
    }
}

void right2(){
    for (int i = n; i >= 1; i--){
        while (!sk.empty() && b[i] <= b[sk.top()]) sk.pop();
        if (sk.empty()) rr1[i] = n+1;
        else rr1[i] = sk.top();
        sk.push(i);
    }
}

void pr_mb(){
    for (int i = 1; i <= n; i++){
        cout << ll[i] << " " << rr[i] << "\n";
    }
    cout << "\n";
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("RECT.inp", "r", stdin);
    freopen ("RECT.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = m - a[i];
    }
    left();
    sk = stack<int> {};
    right();
    sk = stack<int> {};
    left2();
    sk = stack<int> {};
    right2();
    long long res = -1;
    for (int i = 1; i <= n; i++){
        res = max(res, (rr[i] - ll[i] - 1)*a[i]);
        res = max(res, (rr1[i] - ll1[i] - 1)*b[i]);
    }
    cout << res;
    return 0;
}
