#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MOD = 998244353;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int len = s.length();
    ll ans = 0;
    int start = 1;
    int end = len - 2;
    while(s[start] == s[0]) { ++start; }
    while(s[end] == s[len - 1]) {--end;}

    if (s[0] == s[len - 1]) {
        if(start > end) {
            ans = 1;
            for (int i = 0; i < len; ++i) {
                ans = (ans << 2) % MOD;
            }
            ans = (ans - 1 + MOD) % MOD;
        }
        else  {
            ans = ((ll)(start + 1) * (len - end)) % MOD;
        }
    }
    else {
        // if (start > end) {
            ans = (start + (len - end - 1) + 1) % MOD;
        // }
        // else {
            // ans = (start + len - end - 1) % MOD;
        // }
    }
    cout << ans << endl;
    return 0;
}