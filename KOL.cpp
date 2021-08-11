#include <bits/stdc++.h>
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("KOL.inp", "r", stdin);
    freopen ("KOL.out", "w", stdout);
}

int n,m,q;
int u,v,w;
int a[30001];
struct T{
    int pre, val;
};
T tree[4*30001];

void lazypush(int node){
    int k = node*2;
    int t = tree[node].pre;
    tree[k].pre += t;
    tree[k+1].pre += t;

    tree[k].val += t;
    tree[k+1].val += t;

    tree[node].pre = 0;
}

void update(int node, int l, int r, int f){
    if (r < u || l > v) return;
    if (l >= u && r <= v){
        tree[node].val += f;
        tree[node].pre += f;
        return;
    }
    lazypush(node);
    int mid = (l+r)/2;
    update(node*2, l, mid, f);
    update(node*2+1, mid+1, r, f);
    tree[node].val = min(tree[node*2].val, tree[node*2+1].val);
}

int getmin(int node, int l, int r){
    if (r < u || l > v) return INT_MAX;
    if (l >= u && r <= v){
        return tree[node].val;
    }
    lazypush(node);
    int mid = (l+r)/2;
    int left = getmin(node*2, l, mid);
    int right = getmin(node*2+1, mid+1, r);
    return min(left, right);
}

signed main (){
    setFile();
    cin >> n >> m >> q;
    for (int i = 1; i <= 4*n; i++) tree[i].val = m;
    while (q--){
        cin >> u >> v >> w;
        v--;
        int minn = getmin(1,1,n);
        if (minn >= w){
            cout << "T";
            update(1,1,n,-w);
        }
        else cout << "N";
        cout << "\n";
//        for (int i = 1; i <= 4*n; i++) cout << tree[i].val << " ";
//        cout << "\n";
//        cout << getmin(1,1,n) << "\n";
    }
    return 0;
}
