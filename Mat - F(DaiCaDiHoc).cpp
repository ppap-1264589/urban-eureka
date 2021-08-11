//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 200005
#define maxk 21
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define vi vector<int>
#define vii vector< pii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "numcone"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int M = 2021;
 
int k;
ll n;
 
struct matrix
{
    int val[maxk][maxk];
    matrix()
    {
        memset(val, 0, sizeof(val));
    }
 
    static matrix unit(){
        matrix x;
        for (int i = 0; i <= k; i++) x.val[i][i] = 1;
        return x;
    }
 
    matrix operator * ( const matrix & x)
    {
        matrix res;
        for (int u = 0; u <= k; u++)
            for (int v = 0; v <= k; v++)
                for (int i = 0; i <= k; i++)
                    res.val[u][v] = (val[u][i] * x.val[i][v] + res.val[u][v] ) % M;
        return res;
    }
};
 
matrix P[M];
 
matrix POWW(matrix A, long long b)
{
    matrix C = matrix::unit();
    for ( ; b; b /= 2, A = A * A)
        if (b % 2) C = C * A;
    return C;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n >> k;
    For(i, 0, M-1){
        For(j, 1, k)
            if (i >= j*2 - 2)
            {
                P[i].val[j][j] = j * 2;
                P[i].val[j][j-1] = (i - j* 2 + 2);
            }
    }
    matrix ans = matrix::unit();
    int atleast = (n < M) ? n : M-1;
    for (int i = 2; i <= atleast; i++)
        ans = P[i] * ans;
    For(i, 0, M-1){
        For(j, 1, k)
            {
                P[i].val[j][j] = j * 2;
                P[i].val[j][j-1] = (i - j* 2 + 2 + M) % M;
            }
    }
 
    n -= atleast;
    matrix circle = matrix::unit();
    for (int i = 0; i < M; i++) circle = P[i] * circle;
    circle = POWW(circle, n/M);
    ans = circle * ans;
    n %= M;
    for (int i = 0; i < n; i++)
        ans = P[i] * ans;
    cout << ans.val[k][1];
    return 0;
}