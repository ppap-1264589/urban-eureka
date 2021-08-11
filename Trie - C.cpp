#include <bits/stdc++.h>

#define Task                    "C"
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

const int maxn = 1000001;
struct Tree{
    int child[27];
    bool IE;
};
Tree T[maxn];
int F[maxn];
int r;
int n;

void plusmod(int& a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
}

void Add(string s){
    int x = 0;
    for (char c : s){
        int id = c - 'a' + 1;
        if (T[x].child[id] == 0) T[x].child[id] = ++r;
        x = T[x].child[id];
    }
    T[x].IE = 1;
}


signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string s;
    up(i, 1, n){
        cin >> s;
        Add(s);
    }

    string x;
    cin >> x;
    n = x.size();

    F[n] = 1;
    for (int i = n-1; i >= 0; i--){
        int nod = 0;
        for (int j = i; j <= n; j++){
            int v = x[j] - 'a' + 1;
            //cout << T[nod].child[v] << "\n";
            if (T[nod].child[v] == 0) break;
            nod = T[nod].child[v];
            if (T[nod].IE) plusmod(F[i], F[j+1]);
            //for (int i = 0; i <= n; i++) cout << F[i] << " ";
            //cout << "\n";
        }
        //cout << "\n";
    }

    //up(i, 0, n) cout << F[i] << " ";
    cout << F[0];
    return 0;
}
