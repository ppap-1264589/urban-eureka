#include <bits/stdc++.h>

#define Task                    "E"
#define ll                      long long
#define bit(x,i)                ((x >> i) & 1)
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

const int maxn = 10000001;
int n;
int child[maxn][2];
int val[maxn];
int a[maxn];
int cnt;

void add(int x){
    int nod = 0;
    down (i, 30, 0){
        int id = bit(x, i);
        if (child[nod][id] == 0) child[nod][id] = ++cnt;
        nod = child[nod][id];
    }
    val[nod] = x;
}

int check(int x){
    int nod = 0;
    down(i, 30, 0){
        int id = bit(x, i);
        if (child[nod][1-id] != 0){
            nod = child[nod][1-id];
        }
        else nod = child[nod][id];
    }
//    cout << val[nod] << " ";
//    cout << x << " ";
//    cout << (val[nod] ^ x) << " ";
    return (val[nod] ^ x);
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int maxx = INT_MIN;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        add(a[i]);
    }
    for (int i = 1; i <= n; i++){
        maxx = max(maxx, check(a[i]));
    }
    cout << maxx;
    return 0;
}
