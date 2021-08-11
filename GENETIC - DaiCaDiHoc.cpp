//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 25
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "genetic"
#define bit(x, i) ((x>>i) & 1)

using namespace std;

typedef long long ll;
typedef long double ld;
int n, a[maxn], b[maxn], flag[maxn];
int Next[1<<maxn];
ll dp[1<<maxn];

void Read(int pos[]){
    For(i, 1, n){
        int x; cin >> x; pos[x-1] = i;
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    Read(a); Read(b);
    int last = (1 << n) - 1;
    for (int i = 0; i < n; i++){
        flag[i] = last;
        for (int j = 0; j < n; j++)
            if (a[j] < a[i] && b[j] < b[i]) flag[i] -= 1 << j;
    }
    Next[0] = last; dp[0] = 1;
    for (int x = 0; x <= last; x++){
        for (int i = 0; i < n; i++)
            if ((bit(x, i) == 0) && bit(Next[x], i)){
                Next[x | (1<<i)] = Next[x] & flag[i];
                dp[x | (1<<i)] += dp[x];
            }
    }
    cout << dp[last];
    return 0;
}

