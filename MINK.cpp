///Template created by PPAP_1264589
#include <bits/stdc++.h>
#define Task              "MINK"
#define ll                long long
#define up(i,a,b)         for (int i = (a); i <= (b); i++)
#define down(i,a,b)       for (int i = (a); i >= (b); i--)
using namespace std;

void setFile(){
    ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
}

deque<int> de;
int a[1000001];
int s[1000001];
int n,k;

void stacking()
{
    int l = 1, r = 0;
    for (int i = 1; i <= k; i++)
    {
        while (r != l-1 && a[i] < a[s[r]]) r--;
        s[++r] = i;
    }
    cout << a[s[l]] << " ";
    for (int i = k+1; i <= n; i++)
    {
        while (s[l] <= i-k && l != r+1) l++;
        while (r != l-1 && a[i] < a[s[r]]) r--;
        s[++r] = i;
        cout << a[s[l]] << " ";
    }
    cout << "\n";
}

void stacking2(){
    up(i, 1, k){
        while (!de.empty() && a[i] < a[de.back()]){
            de.pop_back();
        }
        de.push_back(i);
    }
    cout << a[de.front()] << " ";
    up(i, k+1, n){
        if (!de.empty() && de.front() + k <= i) de.pop_front();
        while (!de.empty() && a[i] < a[de.back()]) de.pop_back();
        de.push_back(i);
        cout << a[de.front()] << " ";
    }
    cout << "\n";
}

int main (){
    setFile();
    int tt;
    cin >> tt;
    while (tt--){
        cin >> n >> k;
        up(i, 1, n) cin >> a[i];
        stacking2();
        de.clear();
    }
    return 0;
}
