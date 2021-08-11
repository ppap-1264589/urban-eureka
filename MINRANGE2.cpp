#include <bits/stdc++.h>
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("MINRANGE2.inp", "r", stdin);
    freopen ("MINRANGE2.out", "w", stdout);
}

int n,m;
int u,v,w;
struct T{
    int val, pre;
};
int a[100001];
T tree[4*100001];

void build(int node, int l, int r){
    if (l == r){
        tree[node].val = a[r];
        return;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node].val = min(tree[node*2].val, tree[node*2+1].val);
}

void lazypush(int node){
    int k = node*2;
    int t = tree[node].pre;
    tree[k].val = tree[k+1].val = tree[k].pre = tree[k+1].pre = t;
    tree[node].pre = 0;
}

void update(int node, int l, int r){
    if (r < u || l > v){
        return;
    }
    if (l >= u && r <= v){
        tree[node].pre = w;
        tree[node].val = w;
        return;
    }
    if (tree[node].pre != 0) lazypush(node);
    int mid = (l+r)/2;
    update(node*2, l, mid);
    update(node*2+1, mid+1, r);
    tree[node].val = min(tree[node*2].val, tree[node*2+1].val);
}

int getmin(int node, int l, int r){
    if (r < u || l > v) return INT_MAX;
    if (l >= u && r <= v){
        return tree[node].val;
    }
    if (tree[node].pre != 0) lazypush(node);
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
        cin >> c;
        cin >> u >> v;
        if (c == 1) {
            cin >> w;
            update(1, 1, n);
        }
        else cout << getmin(1, 1, n) << "\n";
    }
    //for (int i = 1; i <= 4*n; i++) cout << tree[i].val << " ";
}
