#include <bits/stdc++.h>

#define Task                    "D"
#define ll                      long long
#define bit(x,i)                (x & (1 << (i)))
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

int n,q;
int child[10000001][2]; // I realized that using struct, in some cases, is a really stupid idea
int val[10000001];      // Because it never noficate that I'm making a RTE
int num[10000001];
int cnt = 0;

void Add(int x){
    int nod = 0;
    for (short i = 30; i >= 0; i--){
        bool id = bit(x, i);
        if (child[nod][id] == 0) child[nod][id] = ++cnt;
        nod = child[nod][id];
        num[nod]++;
    }
    val[nod] = x;
}

int get(int k){
    int nod = 0;
    int res = 0;
    for (short i = 30; i >= 0; i--){
        if (child[nod][0] == 0 || num[child[nod][0]] < k){
            k -= num[child[nod][0]];
            nod = child[nod][1];
            res = res * 2 + 1;
        }
        else {
            nod = child[nod][0];
            res = res * 2;
        }
    }
    return val[nod];
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int c,x;
    for (int i = 1; i <= n; i++){
        cin >> c >> x;
        if (c == 1){
            Add(x);
        }
        else {
            cout << get(x) << "\n";
        }
    }
    return 0;
}
