#include <bits/stdc++.h>

#define Task                    "A"
#define ll                      long long
#define bit(x,i)                (x & (1 << (i)))
#define trail0(x)               (x & (-x))
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
#define down(i,a,b)             for (int i = (a); i >= (b); i--)
#define MOD                     1000000007
#define base                    311
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 1000001;

struct nod{
    int child[27];
    bool IE;
};

struct nod T[maxn];
int n,m,depth;

void Add(string s){
    int x = 0; // root;
    for (char c : s){
        int id = c - 'a' + 1;
        if (T[x].child[id] == 0) T[x].child[id] = ++depth;
        x = T[x].child[id];
    }
    T[x].IE = 1;
}

bool Find(string s){
    int x = 0;
    for (char c : s){
        int id = c - 'a' + 1;
        if (T[x].child[id] == 0) return 0;
        x = T[x].child[id];
    }
    return T[x].IE;
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> n;
    while (n--){
        cin >> s;
        Add(s);
    }
    cin >> m;
    while (cin >> s){
        cout << Find(s) << "\n";
    }
    return 0;
}
