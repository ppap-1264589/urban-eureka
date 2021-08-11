#include <bits/stdc++.h>
#define int long long
#define bit(x,i) ((x >> i) & 1)
using namespace std;
 
int st[200];
int dem = 0;
int a[8][100001];
int f[1 << 8][100001];
int n;
 
void init(){
    for (int state = 0; state < (1 << 8); state++){
        if ((state & (state >> 1)) == 0){
            st[++dem] = state;
        }
    }
}
 
void in(){
    cin >> n;
    for (int i = 0; i < 8; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}
 
void dp_bit(){
    for (int j = 1; j <= n; j++){
        for (int state = 1; state <= dem; state++){
            int x = st[state];
            for (int i = 0; i < 8; i++){
                if (bit(x, i)){
                    f[x][j] += a[i][j];
                }
            }
 
            int maxx = INT_MIN;
            for (int r = 1; r <= dem; r++){
                int k = st[r];
                if ((x & k) == 0){
                    maxx = max(maxx, f[k][j-1]);
                }
            }
            f[x][j] += maxx;
        }
    }
}
 
void pr_mb(){
    for (int i = 0; i < (1 << 8); i++){
        for (int j = 1; j <= n; j++){
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
 
int result(int n){
    int maxx = INT_MIN;
    for (int i = 1; i <= dem; i++){
        maxx = max(maxx, f[st[i]][n]);
    }
    int maxx2 = INT_MIN;
    for (int i = 0; i < 8; i++){
        for (int j = 1; j <= n; j++){
            maxx2 = max(maxx2, a[i][j]);
        }
    }
    if (maxx2 < 0) return maxx2;
    else return maxx;
}
 
signed main(){
    init();
    in();
    dp_bit();
    //pr_mb();
    cout << result(n);
    return 0;
}
 