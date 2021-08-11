#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef pair<ll, ll> pll;

#define mod 1000000007
#define mod2 1000000014000000049
#define x 1000007
#define x2 2000009
#define maxn 1000001

int n;
pll h[maxn];

void calh(){
    h[0] = {1, 1};
    for(int i = 1; i <= n; i ++){
        h[i].first = (h[i - 1].first * x) % mod;
        h[i].second = (h[i - 1].second * x2) % mod;
    }
}

vector<pll> Hash(string & s){
    vector<pll>res(s.size(), {0, 0});
    for(int i = 1; i < s.size(); i ++){
        res[i].first = (res[i - 1].first * x + s[i]) % mod;
        res[i].second = (res[i - 1].second * x2 + s[i]) % mod;
    }
    return res;
}

pll get(vector<pll> & a, int l, int r){
    ll t = (a[r].first - a[l - 1].first * h[r - l + 1].first + mod2) % mod;
    ll k = (a[r].second - a[l - 1].second * h[r - l + 1].second + mod2) % mod;
    return {t, k};
}

bool check(vector<pll> & a, vector< pll> & b, int k){
    map<pll, bool> mp;
    for(int i = 1; i <= n; i ++){
        mp[get(a, i, k + i - 1)] = true;
    }
    // for(auto i : mp){
    //     cout << i.first.first << " " << i.first.second << endl;
    // }
    for(int i = 1; i <= n; i ++){
        if(mp[get(b, i, k + i - 1)]) return 1;
    }
    return 0;
}

int main(){
    string a, b;
    cin >> a >> b;
    n = a.size();
    a = "#" + a + a;
    b = "#" + b + b;
    int res = 0;
    calh();
    vector<pll> hsa = Hash(a);
    vector<pll> hsb = Hash(b);
    for(int i = log2(n); i >= 0; i --){
        if(res + (1 << i) <= n && check(hsa, hsb, res + (1 << i))) res += 1 << i;
    }
    cout << res;
    return 0;
}