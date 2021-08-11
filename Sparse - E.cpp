#include <bits/stdc++.h>

#define Task                    "E"
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
#define int long long
void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 2*100001;
int n,m;
long long sp[19][maxn];
int cost,l,r;

void Sparse(){
    up(i, 1, 17){
        for (int j = 1; j + (1 << i) - 1 <= n; j++){
            sp[i][j] = min(sp[i-1][j], sp[i-1][j + (1 << (i-1))]);
        }
    }
}

int getmin(int pos){
    down(i, 17, 0){
        if (pos + (1 << i) - 1 <= n && sp[i][pos] > cost){
            pos += (1 << i);
        }
    }
    return pos;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    up(i, 1, n){
        cin >> sp[0][i];
    }
    Sparse();

    while (m--){
        cin >> cost >> l >> r;
        while (l <= r){
            l = getmin(l);
            if (l > r) break;
            cost %= sp[0][l];
        }
        cout << cost << "\n";
    }
    return 0;
}
