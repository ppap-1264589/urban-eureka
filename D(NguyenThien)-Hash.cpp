#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X 2000009
#define mod 1000000007
#define mod2 1ll * mod * mod 
#define maxn 2000004

ll h[maxn];
string res = "NOT POSSIBLE";
ll resCode = -1;

class Hash{
private:
    string s;
    vector<ll> hs;
    int n;
public:
    /// base: 1 -> n
    Hash(string s){
        this-> s = s;
        n = s.size();
        hs.resize(s.size());
        init();
    }
    void init(){
        for(int i = 1; i < n; i ++){
            hs[i] = (hs[i - 1] * X + s[i]) % mod;
        }
    }
    ll get(int l){
        return hs[l];
    }
    ll get(int l, int r){
        return (hs[r] - hs[l - 1] * h[r - l + 1] + mod2) % mod;
    }
    int size(){
        return n;
    }
    ll getRemove(int l){
        return (get(l + 1, n - 1) + get(l - 1) * h[n - l - 1]) % mod;
        //cout << res << "\n";
    }
};

ll HASH(string& a){
    ll ans = 0;
    for(int i = 1; i < a.size(); i ++){
        ans = (ans * X + a[i]) % mod;
    }
    return ans;
}

void inith(int n){
    h[0] = 1;
    for(int i = 1; i <= n; i ++){
        h[i] = (h[i - 1] * X) % mod;
    }
}

string sol(string &s, int k, int n){
    if(k <= n) return s.substr(n + 1);
    return  s.substr(0, n);
}

void check(string& s, string s1,  ll a, Hash b, int t){
    //cout << "a: " << a << "\n";
    for(int i = 1; i < b.size(); i ++){
        if(b.getRemove(i) == a){
            if(resCode == -1) {
                res = s1;
                resCode = a;
            }
            else if(resCode != a) res = "NOT UNIQUE";
        } 
    }
}

int main(){
    string s;
    cin >> s;
    int n = s.size() / 2;
    inith(s.size() / 2 + 3);
    string a1 = " " + s.substr(0, n); 
    string b1 = " " + s.substr(n);
    check(s, a1, HASH(a1), Hash(b1), n - 1);
    string b2 = " " + s.substr(0, n + 1);
    string a2 = " " + s.substr(n + 1);
    check(s, a2, HASH(a2), Hash(b2), -1);
    cout << res;
    return 0;
}