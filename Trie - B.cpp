#include <bits/stdc++.h>

#define Task                    "B"
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
int n,m,depth;
int dem = 0;
struct nod{
    pair<int, int> child[27];
    bool IE;
    int num;
};
nod T[maxn];

void Add(string s){
    int x = 0;
    for (char c : s){
        int id = c - 'a' + 1;
        if (T[x].child[id].f == 0) T[x].child[id].f = ++depth;
        x = T[x].child[id].f;
        T[x].child[id].s++;
    }
    T[x].IE = 1;
}

int Check(string s){
    dem = 0;
    int x = 0;
    int id = 0;
    for (char c : s){
        id = c - 'a' + 1;
        if (T[x].child[id].f == 0) return 0;
        x = T[x].child[id].f;
    }
    return T[x].child[id].s;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        Add(s);
    }
    cin >> m;
    while (cin >> s){
        cout << Check(s) << "\n";
    }
    return 0;
}

