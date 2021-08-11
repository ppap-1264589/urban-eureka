#include <bits/stdc++.h>
#define bit(x,i) (x & (1 << (i)))
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("SELECT.inp", "r", stdin);
    freopen ("SELECT.out", "w", stdout);
}

int n;
int st[] = {0,1,2,4,5,8,9,10}; // no adjaction 1-bit
int a[4][100001];
int f[11][100001]; /// 100001: REMEMBER to plus 1 when you cin from 1, not from 0

void in(){
    cin >> n;
    for (int i = 0; i < 4; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void dp_bit(){
    for (int j = 1; j <= n; j++){ // iterate from all columns
        for (int state = 0; state < 8; state++){ // for each columns we have selection
            int x = st[state];

            for (int i = 0; i < 4; i++){
                if (bit(x, i)) f[x][j] += a[i][j]; // each selection plus into caculation
            }

            int maxx = INT_MIN;
            for (int k = 0; k < 8; k++){
                int y = st[k];
                if ((x & y) == 0){
                    maxx = max(maxx, f[y][j-1]); // Dp
                }
            }
            f[x][j] += maxx;
        }
    }
}

void pr_mb(){
    for (int i = 0; i <= 10; i++){
        for (int j = 0; j < n; j++){
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

signed main (){
    setFile();
    in();
    dp_bit();
    int maxx = INT_MIN;
    for (int i = 0; i < 8; i++){
        maxx = max(maxx, f[st[i]][n]);
    }
    int maxx2 = INT_MIN;
    for (int i = 0; i < 4; i++){
        for (int j = 1; j <= n; j++){
            maxx2 = max(maxx2, a[i][j]);
        }
    }
    if (maxx2 < 0) cout << maxx2; // If the whole array contains negative values
    else cout << maxx;
    //pr_mb();
    return 0;
}
