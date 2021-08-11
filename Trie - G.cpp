#include <bits/stdc++.h>

#define Task                    "G"
using namespace std;

void setFile(){
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

const int maxn = 1000001;
int n,m;
struct Trie{
    int child[27];
    int depth;
};
Trie T[maxn];
int cnt;
string dict[maxn];
int res;

void Add(string s, int i){
    int nod = 0;
    for (char c : s){
        int id = c - 'a' + 1;
        if (!T[nod].child[id]) T[nod].child[id] = ++cnt;
        nod = T[nod].child[id];
    }
    if (!T[nod].depth) T[nod].depth = i;
}

void findstring(int nod, int i, string a){ // Force tim ra xau dai nhat
    int pos2 = T[nod].depth;
    if (pos2){
        if (dict[res].size() == dict[pos2].size()) res = min(res, pos2); // Thu tu tu dien nho nhat
        if (dict[res].size() < dict[pos2].size()) res = pos2;
    }

    if (i == (int)a.size()) return;
    findstring(nod, i+1, a);
    int id = a[i] - 'a' + 1;
    findstring(T[nod].child[id], i+1, a);
}

string conv(string g){
    sort(g.begin(), g.end());
    return g;
}

void In(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> dict[i];
    }
    sort(dict + 1, dict + n + 1);
    for (int i = 1; i <= n; i++) Add(conv(dict[i]), i);
}

signed main (){
    setFile();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    In();
    cin >> m;
    while (m--){
        string a;
        cin >> a;
        a = conv(a);
        res = 0;
        findstring(0, 0, a);
        if (res) cout << dict[res];
        else cout << "IMPOSSIBLE";
        cout << "\n";
    }
    return 0;
}
