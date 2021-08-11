#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Task "QUEUE"
//http://cpp.sh/9ozksz
using namespace std;
void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

int n;
int a[21][21];
long long f[2000000];

void in(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
}

void Dp_bit(){
    for (int st = 0; st < (1 << n); st++){
        int k = __builtin_popcount(st);
        for (int i = 0; i < n; i++){
            if (!(st >> i & 1)){
                f[st | (1 << i)] = max(f[st | (1 << i)], f[st] + a[i][k]);
            }
            //cout << (st | (1 << (i-1))) << " " << f[(st | (1 << (i-1)))] << endl;
        }
    }
    cout << f[(1 << n) - 1];
}

void Dp_bit2(){
    for (int st = 0; st < (1 << n); st++){
        int k = __builtin_popcount(st);
        for (int i = 0; i < n; i++){
            if (st >> i & 1){
                f[st] = max(f[st], f[st &~ (1 << i)] + a[i][k-1]);
            }
        }
    }
    cout << f[(1 << n) - 1];
}

int main (){
    IOS
    setFile();
    in();
    Dp_bit2();
}
