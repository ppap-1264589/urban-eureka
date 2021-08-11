#include <bits/stdc++.h>

#define Task            "BIT2D"                                  ///map of knowledge
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
using namespace std;


const int MAXDATA = 201;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<mt19937::result_type> random_number(1, MAXDATA);

const int maxn = 1001;
const int MAXUPDATE = 2500;
const int MAXQUERY = 2500;
const int n = 200;
const int m = 200;

int n,m;
struct testcase{
    int c;
    int x,y,val;
    bool dei;
};

int randome(){
    return random_number(RNG);
}

vector<testcase> UU;

void randome_update(){
    char c[2] = {'U', 'S'};

    int p = MAXUPDATE;
    up(i, 1, p){
        int cc = randome() % 2;
        int u = randome() % n + 1;
        int v = randome() % m + 1;
        int val = randome() % MAXDATA + 1;
        UU.pb({(int)c[cc], u, v, val, 1});
    }
}

void randome_get(){
    int p = MAXQUERY;
    up(i, 1, p){
        int u = randome() % n + 1;
        int v = randome() % m + 1;
        int x = randome() % n + 1;
        int y = randome() % m + 1;
        UU.pb({u, v, x, y, 0});
    }
}

void modify_testcase(){
    cout << UU.size() << "\n"; // Queries

    shuffle(UU.begin(), UU.end(), RNG);
    up(i, 0, (int)UU.size()-1){

        int u = UU[i].c;
        int v = UU[i].x;
        int x = UU[i].y;
        int y = UU[i].val;

        if (UU[i].dei == 1){
            cout << 'U' << " " << v << " " << x << " " << y << "\n";
        }
        else {
            int d1 = min(u, x);
            int d2 = min(v, y);
            int d3 = max(u, x);
            int d4 = max(v, y);
            cout << 'S' << " " << d1 << " " << d2 << " " << d3 << " " << d4 << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);

    cout << n << " " << m << "\n";

    randome_update();
    randome_get();
    modify_testcase();

    return 0;
}

