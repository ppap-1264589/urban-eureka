#include <bits/stdc++.h>

#define Task                    "D"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
#define stt(x,i)                (x & (1 << i))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define base                    311
#define pii                     pair<int, int>
#define f                       first
#define s                       second
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 300001;
int sp[19][maxn];
int n,k;

int get_right(int pos){
    int maxh = sp[0][pos] + k;
    for (int i = 18; i >= 0; i--){
        if (pos + (1 << i) - 1 <= n && sp[i][pos] <= maxh){
            pos += (1 << i);
        }
    }
    return pos;
} // Return R in binary search

int get_left(int pos){
    int maxh = sp[0][pos] + k;
    for (int i = 18; i >= 0; i--){
        if (pos - (1 << i) >= 0 && sp[i][pos - (1 << i) + 1] <= maxh){
            pos -= (1 << i);
        }
    }
    return pos;
} // Return L in binary search

void Sparse(){
    for (int i = 1; i <= 17; i++){
        for (int j = 1; j + (1 << i) - 1 <= n; j++){
            sp[i][j] = max(sp[i-1][j], sp[i-1][j + (1 << (i-1))]);
        }
    }
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    up(i, 1, n){
        cin >> sp[0][i];
    }
    sp[0][n+1] = INT_MAX;
    //sp[0][0] = INT_MAX;
    Sparse();
    up(i, 1, n){
        cout << get_right(i) - get_left(i) - 1 << " ";
    }

    return 0;
}
