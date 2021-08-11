#include <bits/stdc++.h>
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("MAXRANGE.inp", "r", stdin);
    freopen ("MAXRANGE.out", "w", stdout);
}

int n,m;
int u,v;
int a[100001];
int tree[4*100001];
int id[4*100001];

void build(int node, int l, int r){
    if (l == r){
        tree[node] = a[r];
        id[r] = node;
        return;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

void update(int pos){
    int node = id[pos];
    tree[node] = a[pos] = v;
    while (node > 1){
        node /= 2;
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

int getmax(int node, int l, int r){
    if (r < u || l > v) return INT_MIN;
    if (l >= u && r <= v) return tree[node];
    int mid = (l+r)/2;
    int maxleft = getmax(node*2, l, mid);
    int maxright = getmax(node*2+1, mid+1, r);
    return max(maxleft, maxright);
}

int main (){
    setFile();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--){
        int c;
        cin >> c;
        cin >> u >> v;
        if (c == 1) {
            update(u);
        }
        else cout << getmax(1, 1, n) << "\n";
    }
    //for (int i = 1; i <= 4*n; i++) cout << tree[i].val << " ";
}
