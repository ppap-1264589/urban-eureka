#include <bits/stdc++.h>
#define Task            "A"
#define bit(x, i)       ((x >> i) & 1)
#define trail0(x)       (x & (-x))
#define up(i,a,b)       for (int i = (a); i <= (b); i++)
#define down(i,a,b)     for (int i = (a); i >= (b); i--)
#define MOD             1000000007
#define base            311
#define pii             pair<int, int>
#define f               first
#define s               second
#define pb              push_back
#define ep              emplace_back
#define MAX_ARR_SIZE    486010000

using namespace std;

int a[20];
int b[20];
int state[1 << 20];
int Next[1 << 20];
long long dp[1 << 20];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    int n;
    cin >> n;
    int x;
    up(i, 1, n){
        cin >> x;
        a[x-1] = i;
    }
    up(i, 1, n){
        cin >> x;
        b[x-1] = i;
    }
    int last = (1 << n)-1;
    for (int i = 0; i < n; i++){
        state[i] = last;
        for (int j = 0; j < n; j++){
            if (a[j] < a[i] && b[j] < b[i]){
                state[i] -= (1 << j);
            }
        }
    }

    Next[0] = last;
    dp[0] = 1;
    for (int x = 0; x <= last; x++){
        for (int i = 0; i < n; i++){
            if (bit(x, i) == 0 && bit(Next[x], i)){
                Next[x | (1 << i)] = Next[x] & state[i];
                dp[x | (1 << i)] += dp[x];
            }
        }
    }
    up(i, 0, last) cout << dp[i] << " ";
    cout << dp[last];
    return 0;
}
//code by Dai Ca Di Hoc
