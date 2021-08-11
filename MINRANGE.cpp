#include <bits/stdc++.h>
using namespace std;
void setFile(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("MINRANGE.inp", "r", stdin);
    freopen ("MINRANGE.out", "w", stdout);
}

int n,m;
int a[100001];
int tree[4*100001];
int id[100001];
int u,v;

void build(int node, int l, int r){
    if (l == r){
        tree[node] = a[r];
        id[r] = node;
        return;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

void update(int pos, int val){
    int node = id[pos];
    tree[node] = a[pos] = val;
    while (node > 1){
        node /= 2;
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int getmin(int node, int l, int r){
    if (l >= u && r <= v) return tree[node];
    if (r < u || l > v) return INT_MAX;
    int mid = (l+r)/2;
    int minleft = getmin(node*2, l, mid);
    int minright = getmin(node*2+1, mid+1, r);
    return min(minleft, minright);
}

int main (){
    setFile();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--){
        int c;
        cin >> c >> u >> v;
        if (c == 1){
            update(u, v);
        }
        else {
            cout << getmin(1, 1, n) << "\n";
        }
    }
    return 0;
}
