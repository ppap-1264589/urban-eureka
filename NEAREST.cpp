///Template created by PPAP_1264589
#include <bits/stdc++.h>
#define Task              "NEAREST"
#define ll                long long
#define ull               unsigned long long
#define rollup(i,a,b)     for (int i = (a); i <= (b); i++)
#define rolldown(i,a,b)   for (int i = (a); i >= (b); i--)
#define bit(x, i)         ((x >> (i)) & 1)
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

int n;
int a[1000001];
stack<int> sk;
int s[1000001];
int mm1[1000001];
int mm2[1000001];

void left(){
    rollup(i, 1, n){
        while (!sk.empty() && a[i] >= a[sk.top()]){
            sk.pop();
        }
        if (sk.empty()) mm1[i] = 0;
        else mm1[i] = sk.top();
        sk.push(i);
    }
}

void right1(){
    int top = 0;
    rolldown(i, n, 1){
        while (top > 0 && a[i] >= a[s[top]]) top--;
        if (top == 0) mm2[i] = 0;
        else mm2[i] = s[top];
        s[++top] = i;
    }
}

void right2(){
    rolldown(i, n, 1){
        while (!sk.empty() && a[i] >= a[sk.top()]){
            sk.pop();
        }
        if (sk.empty()) mm2[i] = 0;
        else mm2[i] = sk.top();
        sk.push(i);
    }
}

int main (){
    setFile();
    cin >> n;
    rollup(i, 1, n) cin >> a[i];
    left();
    while (!sk.empty()) sk.pop();
    right2();
    rollup(i, 1, n) cout << mm1[i] << " " << mm2[i] << "\n";
    return 0;
}
///From VNOI with love
