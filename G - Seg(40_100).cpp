#include <bits/stdc++.h>

#define Task            "A"                                  /// map of knowledge
#define bit(x, i)       ((x >> i) & 1)                       //+ Binary Lifting
#define trail0(x)       (x & (-x))                           //+ Hash Table
#define up(i,a,b)       for (int i = (a); i <= (b); i++)     //+ Trie Tree
#define down(i,a,b)     for (int i = (a); i >= (b); i--)     //+ Sparse Table - RMQ
#define MOD             1000000007                           //+ Matrix
#define base            311                                  //+ DSU
#define pii             pair<int, int>                       //+ Joints - Bridges
#define f               first                                //+ SCC
#define s               second                               //+ Z-KMP
#define pb              push_back                            //+ MST
#define ep              emplace_back                         //+ LCA
#define MAX_ARR_SIZE    486010000                            //+ Shortest Path
                                                             //+ Fenwick Tree
                                                             //+ Segment Tree
using namespace std;

const int maxn = 2*100001;
struct Array{
    int pos;
    int low;
    int up;
    int door;
};
struct Segment_tree{
    int cnt;
    int val;
};
Array save[maxn*2];
Segment_tree T[maxn*2*4];
int n;

bool compare(const Array& x, const Array& y){
    if (x.pos == y.pos) return (x.door < y.door);
    return (x.pos < y.pos);
}

int u, v, d;
void update(int nod, int l, int r){
    if (r < u || l > v) return;
    if (l >= u && r <= v){
        T[nod].cnt += d;
        if (d == 1){
            T[nod].val = r - l + 1;
        }
        else if (T[nod].cnt == 0){
            T[nod].val = T[nod*2].val + T[nod*2+1].val;
        }
        return;
    }

    int mid = (l+r)/2;
    update(nod*2, l, mid);
    update(nod*2+1, mid+1, r);
    if (T[nod].cnt == 0){
        T[nod].val = T[nod*2].val + T[nod*2+1].val;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    cin >> n;
    int maxy = -1;
    up(i, 1, n){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        x1++;
        x2++;
        y1++;
        y2++;
        save[i] = {x1, y1, y2, 1};
        save[i+n] = {x2, y1, y2, -1};
        maxy = max(max(maxy, y1), y2);
    }
    sort(save+1, save+n*2+1, compare);
//    up(i, 1, 2*n){
//        cout << save[i].pos << " " << save[i].upper << " " << save[i].lower << " " << save[i].door << "\n";
//    }

    int res = 0;
    up(i, 1, n*2){
        res += T[1].val * (save[i].pos - save[i-1].pos);
        u = save[i].low;
        v = save[i].up-1;
        d = save[i].door;
        update(1, 0, maxy);
    }
    cout << res;
    return 0;
}
