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
#define Task "compression"
#define maxn 2000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define haimu(x) (1ll << x)
#define ll long long

using namespace std;

int n, m, cnt = 0;
bool take[maxn];
bool Isend[maxn];
int Child[maxn][26];
long long res[maxn];
long long ss[maxn];

void Add (string s){
    int node = 0;
    for (char c : s){
        int x = c - 'a'; // a -> 0; b -> 1; c -> 2; ...
        if (Child[node][x] == 0) Child[node][x] = ++cnt;
        node = Child[node][x];
    }
    Isend[node] = 1;
}

void Calc(int node, int depth){

    ll sum = 0;
    for (int i = 0; i < 26; i++)
        if (Child[node][i]){
            int con = Child[node][i];
            Calc(con, depth-1);
            sum += res[con];
        }
    ss[node] = sum;
    if (!Isend[node] && sum > 0 && sum < haimu(depth)) res[node] = sum;
        else {
            res[node] = haimu(depth);
            take[node] = 1;
        }
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        Add(s);
    }
    Calc(0, 40);
//    cout << n << endl;
//    for (int i = 1; i <= cnt; i++)
//        cout << res[i] << " ";
//    cout << res[0] << endl;
    cout << ss[0] << endl;
//    long long rsum = 0;
//    for (int i = 0; i < 26; i++)
//        if (Child[0][i]) rsum += sum[Child[0][i]];
//    cout << rsum;
//    cerr << rsum;
    return 0;
}

