//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "substrg"
#define maxn 200005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

string T, P;
int m, n, pos[130];
int a[maxn*2], pi[maxn], res[maxn], cnt = 0, c[maxn];

void prepare(string S, int pre[]){
    reset(pos);
    for (int i = 1; i < S.length(); i++){
        if (pos[S[i]]) pre[i] = i - pos[S[i]];
            else pre[i] = 0;
        pos[S[i]] = i;
    }
}

bool khop(int u, int x){
    if (a[u]) return a[u] == x;
    return x == 0 || x >= u;
}

void Calc(){
    for (int k = pi[0] = -1, i = 1; i <= m+n+1; i++){
        while (k >= 0 && !khop(k+1, a[i])) k = pi[k];
        pi[i] = ++k;
        if (pi[i] == n) {
            res[++cnt] = i;
            k = pi[k];
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> T >> P;
    m = T.length(); n = P.length();
    T = "*" + T; P = "*" + P;
    prepare(P, a);
    a[n+1] = -1;
    prepare(T, &a[n+1]);
    Calc();
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) cout << res[i] - n - n << " ";
    return 0;
}
