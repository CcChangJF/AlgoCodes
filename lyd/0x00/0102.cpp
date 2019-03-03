#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string toStr(ll n) {
    if (0 == n) {
        return "0";
    }
    else {
        vector<char> res;
        while(0 != n) {
            res.push_back(n % 10 + '0');
            n /= 10;
        }
        return string(res.begin(), res.end());
    }
}

ll toLL(string a) {
    ll ans = 0;
    for (int i = a.length() - 1; i >= 0; --i) {
        ans = ans * 10 + a[i] - '0';
    }
    return ans;
}

string multiply(string a, string b) {
    if ("0" == b) { return b; }
    if (a.length() < b.length()) {
        swap(a, b);
    }
    int lena = a.length();
    int lenb = b.length();
    vector<int> res = vector<int>(lena + lenb, 0);
    for (int i = 0; i < lena; ++i) {
        for (int j = 0; j < lenb; ++j) {
            res[i + j] += (a[i] - '0') * (b[j] - '0');
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
        }
    }
    int last = res.size() - 1;
    while(0 == res[last]) { --last;}
    vector<char> resStr = vector<char>(last + 1);
    for (int i = 0; i <= last; ++i) {
        resStr[i] = res[i] + '0';
    }
    return string(resStr.begin(), resStr.end());
}

bool lessLL(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    for (int i = a.length() - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

string subtract(string a, string b) {
    vector<char> res = vector<char>(a.length(), '0');
    int flag = 0;
    int i = 0;
    while(i < b.length() || 0 != flag) {
        int bt = (i < b.length()) ? b[i] : '0';
        if (a[i] + flag >= bt) {
            res[i] = a[i] + flag - bt + '0';
            flag = 0;
        }
        else {
            res[i] = a[i] + flag - bt + '0' + 10;
            flag = -1;
        }
        ++i;
    }
    i = a.length() - 1;
    while('0' == res[i]) {
        --i;
    }
    return string(res.begin(), res.begin() + i + 1);
}

string mod(string a, string b) {
    vector<string> power = vector<string>();
    string two = "2";
    string res = b;
    power.push_back(res);
    while(lessLL(res, a)) {
        res = multiply(res, two);
        // cout << res << endl;
        power.push_back(res);
    }
    int last = power.size() - 2;
    res = a;
    while(!lessLL(res, b) && last >= 0) {
        // cout << power[last] << endl;
        if (!lessLL(res, power[last])) {
            res = subtract(res, power[last]);
            // cout << power[last] << "\t" << res << endl;
        }
        --last;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, p;
    cin >> a >> b >> p;
    string stra = toStr(a);
    string strb = toStr(b);
    string strp = toStr(p);
    // cout << stra << " " << strb << " " << strp << endl;
    string mul = multiply(stra, strb);
    // cout << mul << endl;
    string ansStr = mod(mul, strp);
    ll ans = toLL(ansStr);
    // int ans = 0;
    cout << ans << endl;
    return 0;
}