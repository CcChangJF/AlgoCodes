#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MOD = 998244353;

const int N = 1000005;
ll fac[N];
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fac[0] = 1;
    a[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (fac[i - 1]) * i % MOD;
        a[i] = a[i - 1] * (n + 1 - i) % MOD;
    }
    ll ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        ans = (ans + a[i] * (fac[n - i] - 1)) % MOD;
    }
    ans = (ans + fac[n]) % MOD;
    cout << ans << endl;
    return 0;
}