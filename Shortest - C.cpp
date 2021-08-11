#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
#define up(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define pb push_back
#define ep emplace_back
#define Task "A"
using namespace std;

const int maxn = 155;
struct edge{
    int v,c,d;
};
vector<edge> E[maxn];
int n,m;
int s, f, W;
double d[maxn];
vector<int> C;
priority_queue<pii, vector<pii>, greater<pii>> P;

void in(){
    cin >> n >> m;
    cin >> s >> f >> W;
    int u,v,c,d;
    up(i, 1, m){
        cin >> u >> v >> c >> d;
        E[u].pb({v, c, d});
        E[v].pb({u, c, d});
        C.ep(c);
    }
}

double Dijkstra(int cmin){
    fill(d, d+n+1, 100001);
    d[s] = 0;
    P.push({0, s});
    while (!P.empty()){
        int u = P.top().s;
        int curd = P.top().f; //current delay
        if (u == f){
            return (d[f] + double(W / double(cmin)));
        }
        P.pop();
        if (curd != d[u]) continue;
        for (edge e : E[u]){
            int v = e.v;
            int c = e.c;
            int delay = e.d;
            if (c < cmin) continue; // neu c < cmin thi se mat nhieu time hon -> loai
            if (d[v] > curd + delay){  //tim delay nho nhat
                d[v] = curd + delay;
                P.push({d[v], v});
            }
        }
    }

    return (d[f] + (W / double(cmin)));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    in();
    double res = DBL_MAX;
    for (int c : C){
        res = min(res, Dijkstra(c));
    }
    cout << fixed << setprecision(2);
    cout << res;

    return 0;
}
