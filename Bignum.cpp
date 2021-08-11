#include <bits/stdc++.h>
using namespace std;
// (A + B) * C - D

string add(string a, string b){
    string res = "";
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    int crr = 0;
    for (int i = (int)a.size()-1; i >= 0; i--){
        int t = a[i] + b[i] - 48*2 + crr;
        crr = t/10;
        t %= 10;
        res = char(t+48) + res;
    }
    while (res.size() > 1 && res.front() == 0) res.erase(0, 1);
    if (crr > 0) res = '1' + res;
    return res;
}

string sub(string a, string b){
    string res = "";
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    int brr = 0;

    bool isNeg = false;
    if (a < b){
        swap(a, b);
        isNeg = true;
    }
    for (int i = (int)a.size()-1; i >= 0; i--){
        int t = a[i] - b[i] - brr;
        if (t < 0){
            brr = 1;
            t += 10;
        }
        else brr = 0;
        res = char(t % 10 + 48) + res;
    }
    while (res.size() > 1 && res.front() == '0') res.erase(0, 1);
    if (isNeg) res = '-' + res;
    return res;
}

string mul(string a, string b){
    string res = "";
    int n = a.size();
    int m = b.size();
    int len = n + m - 1;
    int crr = 0;

    for (int i = len; i >= 0; i--){
        int sum = 0;
        for (int j = m-1; j >= 0; j--){
            if (i-j <= n && i-j >= 1){
                int x1 = b[j] - 48;
                int x2 = a[i-j-1] - 48;
                sum += x1*x2;
            }
        }
        sum += crr;
        crr = sum/10;
        res = char(sum % 10 + 48) + res;
    }
    while (res.size() > 1 && res.front() == '0') res.erase(0, 1);
    return res;
}
